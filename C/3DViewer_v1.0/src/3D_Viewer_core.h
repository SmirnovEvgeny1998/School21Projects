#ifndef _3D_VIEWER_CORE_H
#define _3D_VIEWER_CORE_H
#define _GNU_SOURCE
#ifdef __cplusplus
extern "C" {
#endif

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MX_SIZE 3

/** @struct vertex_t
 *  @brief содержит координаты вектора.
 *  @param x
 *  координата x
 *  @param y
 *  координата y
 *  @param z
 *  координата z
 */
typedef struct {
  double x, y, z;
} vertex_t;

/** @struct face_t
 *  @brief размер и точки полигонов.
 *  @param vertices
 *  точки полигонов: связь точек массива vertex_t друг с другом.
 *  @param size
 *  количество точек в полигоне.
 */
typedef struct {
  int *vertices;
  int size;
} face_t;

/** @struct Obj
 *  @brief данные о координатах и полигонах из файла .obj
 *  @param vert_number
 *  количество точек.
 *  @param faces_number
 *  количество полигонов.
 *  @param vert_arr
 *  массив vertex_t размера vert_number.
 *  @param face_arr
 *  массив face_t размера faces_number.
 */
typedef struct {
  int vert_number;
  int faces_number;
  vertex_t *vert_arr;
  face_t *face_arr;
} Obj;

/** @struct matrix_t
 *  @brief матрица 3х3.
 *  @param elements
 *  элементы матрицы.
 */
typedef struct {
  double elements[MX_SIZE][MX_SIZE];
} matrix_t;

Obj *load_obj_info(const char *filename);
FILE *open_file(const char *filename);
int count_lines(FILE *obj_file, const char *s);
vertex_t *get_arr_of_vertices(FILE *obj_file, int v_count);
face_t *get_arr_of_faces(FILE *obj_file, int f_count);

void transform_vertex_massive(vertex_t *vertex, int v_count, matrix_t *matrix);
void transform_vertex(vertex_t *vertex, matrix_t *matrix);
void initialize_rotation_matrix(double x_angle, double y_angle, double z_angle,
                                matrix_t *matrix);
void initialize_scale_matrix(double scale, matrix_t *matrix);
void rotate(vertex_t *vertex, int v_count, double x_angle, double y_angle,
            double z_angle);
void scaling(vertex_t *vert_arr, int v_count, double scale);
void motion_vertex(double range_x, double range_y, double range_z,
                   int vertex_count, vertex_t *vertex);
void free_obj(Obj *o);
void free_arr_of_faces(face_t *arr, int size);
double find_max_coord_of_vert(vertex_t *v_arr, int v_count);

#ifdef __cplusplus
}
#endif

#endif  // _3D_VIEWER_CORE_H
