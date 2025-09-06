#ifndef A1_MAZE_CONTROLLER_H
#define A1_MAZE_CONTROLLER_H

#include "../model/cave.h"

namespace s21 {
class Controller {
 public:
  /**
   @brief Конструктор
   */
  Controller(s21::cave* cave_model) : cave_model_(cave_model){};
  /**
   @brief Деструктор
   */
  ~Controller(){};
  void LoadFromFile(std::string filename);
  void setDeathLimit(int n);
  void setBurthLimit(int n);
  void setFieldValue(int i, int j, int val);
  void updateCave();
  std::vector<std::vector<int> > getField() const;

  //        private:
  cave* cave_model_;
};  // class controller
}  // namespace s21

#endif  // A1_MAZE_CONTROLLER_H
