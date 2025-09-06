#include "./controller.h"

/**
 @brief Загружает пещеру из фаила
 @param filename - путь/название фаила
 */
void s21::Controller::LoadFromFile(std::string filename) {
  cave_model_->LoadCaveFromFile(filename);
}
/**
 @brief Устанавливает пределы "смертности" для клеток пещеры
 @param n - предел
 */
void s21::Controller::setDeathLimit(int n) { cave_model_->setdeathLimit(n); }
/**
 @brief Устанавливает пределы "рождаемости" для клеток пещеры
 @param n - предел
 */
void s21::Controller::setBurthLimit(int n) { cave_model_->setBurthLimit(n); }
/**
 @brief Устанавливает значение заданной клетки пещеры
 @param i - ряд клетки пещеры
 @param j - столбец клетки  пещеры
 @param val - новое значение
 */
void s21::Controller::setFieldValue(int i, int j, int val) {
  cave_model_->setFieldValue(i, j, val);
}
/**
 @brief Обновляет состояние пещеры в одной итерации согласно заданным параметрам
 */
void s21::Controller::updateCave() { cave_model_->update(); }
/**
 @brief Возвращает матрицу пещеры
 */
std::vector<std::vector<int> > s21::Controller::getField() const {
  return cave_model_->getField();
}
