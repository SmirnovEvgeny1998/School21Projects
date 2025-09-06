#include "cave.h"

/**
 @brief Устанавливает пределы "рождаемости" для клеток пещеры
 @param n - предел
 */
void s21::cave::setBurthLimit(int n) {
  if (n < 0) n = 0;
  if (n > 7) n = 7;

  burth_limit = n;
}

/**
 @brief Устанавливает пределы "смертности" для клеток пещеры
 @param n - предел
 */
void s21::cave::setdeathLimit(int n) {
  if (n < 0) n = 0;
  if (n > 7) n = 7;

  death_limit = n;
}

/**
 @brief Устанавливает значение заданной клетки пещеры
 @param i - ряд клетки пещеры
 @param j - столбец клетки  пещеры
 @param value - новое значение
 */
void s21::cave::setFieldValue(int i, int j, int value) { field[i][j] = value; }

/**
 @brief Загружает пещеру из фаила
 @param filename - путь/название фаила
 */
void s21::cave::LoadCaveFromFile(std::string filename) {
  std::ifstream file(filename);
  if (file) {
    file >> x_size >> y_size;
    if (x_size < 0 || y_size < 0 || x_size > 50 || y_size > 50) {
      throw std::invalid_argument("Invalid cave's size");
    } else {
      field.resize(y_size, std::vector<int>(x_size));
      for (int i = 0; i < x_size; i++)
        for (int j = 0; j < y_size; j++) {
          file >> field[i][j];
        }
    }
  } else {
    throw std::invalid_argument("Error occurred while opening file...");
  }
}

/**
 @brief Обновляет состояние пещеры в одной итерации согласно заданным параметрам
 */
void s21::cave::update() {
  std::vector<std::vector<int>> next_field;
  next_field.resize(y_size, std::vector<int>(x_size));
  for (int i = 0; i < x_size; i++)
    for (int j = 0; j < y_size; j++)
      next_field[i][j] = CalcNextStateOfCell(i, j);
  std::swap(next_field, field);
}

/**
 @brief Рассчитывает что случится с заданной клеткой пещеры согласно заданным
 параметрам рождаемости и смертности
 @param x - ряд клетки пещеры
 @param y - столбец клетки пещеры
 */
int s21::cave::CalcNextStateOfCell(int x, int y) {
  int alive_neighbors = 0;
  for (int i = x - 1; i <= x + 1; i++)
    for (int j = y - 1; j <= y + 1; j++) {
      if (i < 0 || j < 0 || i >= x_size || j >= y_size)
        alive_neighbors++;
      else
        alive_neighbors += field[i][j];
    }

  if (field[x][y]) {  // if cell alive
    if (alive_neighbors < death_limit)
      return 0;
    else
      return 1;
  } else {  // if cell dead
    if (alive_neighbors > burth_limit)
      return 1;
    else
      return 0;
  }
}

namespace s21 {
/**
 @brief Возвращает матрицу пещеры
 */
std::vector<std::vector<int>> cave::getField() const { return field; }

}  // namespace s21
