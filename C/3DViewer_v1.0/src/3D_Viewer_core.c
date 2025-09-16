#include "3D_Viewer_core.h"

/**
 * @brief load_obj_info загружает информацию из файла в структуру типа Obj
 * @param filename строка, содержащая имя файла
 * @return указатель на структуру типа Obj (NULL в случае, когда файл не
 * существует)
 */
Obj *load_obj_info(const char *filename) {
  FILE *obj_file = open_file(filename);
  Obj *obj_info = NULL;
  if (obj_file) {
    obj_info = calloc(1, sizeof(Obj));
    obj_info->vert_number = count_lines(obj_file, "v");
    obj_info->faces_number = count_lines(obj_file, "f");
    if (obj_info->vert_number && obj_info->faces_number) {
      obj_info->vert_arr = get_arr_of_vertices(obj_file, obj_info->vert_number);
      obj_info->face_arr = get_arr_of_faces(obj_file, obj_info->faces_number);
    } else {
      free(obj_info);
      obj_info = NULL;
      perror("Corrupted object file");
    }
    fclose(obj_file);
  }
  return obj_info;
}

/**
 * @brief освобождает память структуры типа Obj.
 * @param o структура типа Obj.
 * @return void
 */
void free_obj(Obj *o) {
  if (o) {
    if (o->face_arr) {
      free_arr_of_faces(o->face_arr, o->faces_number);
    }
    if (o->vert_arr) {
      free(o->vert_arr);
    }
    free(o);
  }
}

/**
 * @brief освобождает память массива структур типа face_t.
 * @param arr массив структур типа face_t.
 * @param size размер массива.
 * @return void
 */
void free_arr_of_faces(face_t *arr, int size) {
  if (arr) {
    for (int i = 0; i < size; i++) {
      if ((arr + i)->vertices) {
        free((arr + i)->vertices);
      }
    }
    free(arr);
  }
}

/**
 * @brief open_obj функция для загрузки .obj файла и проверки на его наличие
 * @param filename строка, содержащая имя файла
 * @return указатель на начало файла (NULL в случае, когда файл не существует)
 */
FILE *open_file(const char *filename) {
  FILE *obj_file = fopen(filename, "r");
  if (obj_file == NULL) {
    perror("Error occured while opening file:");
  }
  return obj_file;
}

/**
 * @brief count_lines функция для подсчета строк в файле obj_file, начинающихся
 * на s
 * @param obj_file указатель на файл
 * @param s указатель на строку, с которой должны начинаться искомые строки в
 * файле
 * @return возвращает количество найденных строк
 */
int count_lines(FILE *obj_file, const char *s) {
  int counter = 0;
  size_t n;
  char *line = NULL;
  char str[4] = {0};
  while (getline(&line, &n, obj_file) != -1) {
    int r = sscanf(line, "%3s", str);
    if (r == 1 && !strcmp(str, s)) {
      counter++;
    }
  }
  if (line) free(line);
  fseek(obj_file, 0, SEEK_SET);
  return counter;
}
/**
 * @brief get_arr_of_vertices функция для создания массива вершин типа vertex_t
 * @param obj_file файл, содержащий в себе информацию о вершинах
 * @param v_count количество вершин
 * @return указатель на массив вершин типа vertex_t
 */
vertex_t *get_arr_of_vertices(FILE *obj_file, int v_count) {
  vertex_t *vert_arr = calloc(v_count, sizeof(vertex_t));
  int counter = 0;
  size_t n;
  char *line = NULL;
  char str[4] = {0};
  while (getline(&line, &n, obj_file) != -1) {
    int r = sscanf(line, "%3s", str);
    if (r == 1 && !strcmp(str, "v")) {
      #ifdef linux
      for (int i = 0; i < strlen(line); i++) {
        if (line[i] == '.') {
          line[i] = ',';
        }
      }
      #endif
      double x, y, z;
      if (sscanf(line, "%*s %lf %lf %lf", &x, &y, &z) == 3) {
        vert_arr[counter].x = x;
        vert_arr[counter].y = y;
        vert_arr[counter].z = z;
        counter++;
      }
    }
  }
  if (line) free(line);
  fseek(obj_file, 0, SEEK_SET);
  return vert_arr;
}
/**
 * @brief get_arr_of_faces функция для создания массива структур полигонов типа
 * face_t
 * @param obj_file указатель на файл, содержащий информацию о полигонах
 * @param f_count количество полигонов
 * @return указатель на массив структур полигонов
 */
face_t *get_arr_of_faces(FILE *obj_file, int f_count) {
  face_t *face_arr = (face_t *)malloc(f_count * sizeof(face_t));
  int counter = 0;
  size_t n;
  char *line = NULL;
  char str[100] = {0};
  while (getline(&line, &n, obj_file) != -1) {
    int r = sscanf(line, "%3s", str);
    if (r == 1 && !strcmp(str, "f")) {
      char *tmp_line = line;
      int v_counter = 0;
      int vertex = 0;
      face_arr[counter].vertices = NULL;
      line = strchr(line, ' ') + 1;
      while (line && (sscanf(line, "%d", &(vertex)) == 1)) {
        face_arr[counter].vertices =
            realloc(face_arr[counter].vertices, (v_counter + 1) * sizeof(int));
        face_arr[counter].vertices[v_counter++] = vertex - 1;
        line = strchr(line, ' ');
        if (line) line += 1;
      }
      face_arr[counter].size = v_counter;
      counter += 1;
      line = tmp_line;
    }
  }
  if (line) free(line);
  fseek(obj_file, 0, SEEK_SET);
  return face_arr;
}

/**
 * @brief Функция изменяющая координаты структуры согласно поданой матрице.
 * @param *vertex - ссылка на массив структур, содержащий точки для
 * преобразования.
 * @param v_count - количество вершин объекта/ количество структур в массиве
 * *vertex.
 * @param *matrix - матрица для преобразований точек.
 * @return void
 */
void transform_vertex_massive(vertex_t *vertex, int v_count, matrix_t *matrix) {
  for (int i = 0; i < v_count; i++) {
    transform_vertex(vertex + i, matrix);
  }
}

/**
 * @brief Преобразует вектор матрицей.
 * @param *vertex - ссылка на структуру точки.
 * @param *matrix - матрица преобразования точек.
 * @return void
 */
void transform_vertex(vertex_t *vertex, matrix_t *matrix) {
  double *v_ptr = (double *)vertex;
  double n_coord[MX_SIZE] = {0};
  for (int i = 0; i < MX_SIZE; i++) {
    for (int j = 0; j < MX_SIZE; j++) {
      n_coord[i] += matrix->elements[i][j] * v_ptr[j];
    }
  }
  memcpy(v_ptr, n_coord, sizeof(vertex_t));
}

/**
 * @brief Функция определяющая матрицу трансформации через поданные углы
 * вращения.
 * @param x_angle - угол поворота по оси x.
 * @param y_angle - угол поворота по оси y.
 * @param z_angle - угол поворота по оси z.
 * @param *matrix - ссылка на матрицу для инициализации.
 * @return void
 */
void initialize_rotation_matrix(double x_angle, double y_angle, double z_angle,
                                matrix_t *matrix) {
  matrix->elements[0][0] = cos(y_angle) * cos(z_angle);
  matrix->elements[0][1] = -sin(z_angle) * cos(y_angle);
  matrix->elements[0][2] = sin(y_angle);
  matrix->elements[1][0] =
      sin(x_angle) * sin(y_angle) * cos(z_angle) + sin(z_angle) * cos(x_angle);
  matrix->elements[1][1] =
      -sin(x_angle) * sin(y_angle) * sin(z_angle) + cos(x_angle) * cos(z_angle);
  matrix->elements[1][2] = -sin(x_angle) * cos(y_angle);
  matrix->elements[2][0] =
      sin(x_angle) * sin(z_angle) - sin(y_angle) * cos(x_angle) * cos(z_angle);
  matrix->elements[2][1] =
      sin(x_angle) * cos(z_angle) + sin(y_angle) * sin(z_angle) * cos(x_angle);
  matrix->elements[2][2] = cos(x_angle) * cos(y_angle);
}

/**
 * @brief rotate функция для вращения массива вершин
 * @param vert_arr указатель на массив вершин
 * @param x_angle - угол поворота по оси x.
 * @param y_angle - угол поворота по оси y.
 * @param z_angle - угол поворота по оси z.
 */
void rotate(vertex_t *vert_arr, int v_count, double x_angle, double y_angle,
            double z_angle) {
  matrix_t rotation_matrix;
  initialize_rotation_matrix(x_angle, y_angle, z_angle, &rotation_matrix);
  transform_vertex_massive(vert_arr, v_count, &rotation_matrix);
}

/**
 * @brief Функция добавляющая матрице трансформации масштаб.
 * @param scale - масштаб для изменения.
 * @param *matrix - ссылка на матрицу, с которой будет проводиться скейлинг.
 * @return void
 */
void initialize_scale_matrix(double scale, matrix_t *matrix) {
  for (int i = 0; i < MX_SIZE; i++) {
    for (int j = 0; j < MX_SIZE; j++) {
      if (i == j) {
        matrix->elements[i][j] = scale;
      } else {
        matrix->elements[i][j] = 0;
      }
    }
  }
}

/**
 * @brief scaling функция для масштабирования массива вершин
 * @param vert_arr указатель на массив вершин
 * @param v_count количество вершин
 * @param scale - масштаб для изменения.
 */
void scaling(vertex_t *vert_arr, int v_count, double scale) {
  matrix_t scale_matrix;
  initialize_scale_matrix(scale, &scale_matrix);
  transform_vertex_massive(vert_arr, v_count, &scale_matrix);
}

/**
 * @brief Функция принимающая список vertex_t и смещающая каждую точку на
 * заданные значения.
 * @param range_x - сдвиг по оси x.
 * @param range_x - сдвиг по оси y.
 * @param range_x - сдвиг по оси z.
 * @param vertex_count - количество структур в массиве.
 * @param *vertex - массив вершин объекта.
 * @return void
 */
void motion_vertex(double range_x, double range_y, double range_z,
                   int vertex_count, vertex_t *vertex) {
  for (int i = 0; i < vertex_count; i++) {
    vertex[i].x += range_x;
    vertex[i].y += range_y;
    vertex[i].z += range_z;
  }
}

/**
 * @brief Функция для нахождения максимальной координаты
 * @param v_arr указатель на массив вершин
 * @param v_count количество вершин
 * @return максимальная координата из массива вершин
 */
double find_max_coord_of_vert(vertex_t *v_arr, int v_count) {
  double res;
  double *ptr = (double *)v_arr;
  double max_pos = ptr[0];
  double max_neg = ptr[0];
  for (int i = 0; i < 3 * v_count; i++) {
    if (ptr[i] > max_pos) max_pos = ptr[i];
    if (ptr[i] < max_neg) max_neg = ptr[i];
  }
  max_neg *= -1;
  if (max_pos > max_neg)
    res = max_pos;
  else
    res = max_neg;
  return res;
}
