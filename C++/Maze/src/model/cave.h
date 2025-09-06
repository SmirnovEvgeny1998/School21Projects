#ifndef A1_MAZE_MODEL_CAVE_H
#define A1_MAZE_MODEL_CAVE_H

#include <array>
#include <fstream>
#include <iostream>
#include <vector>

namespace s21 {

const int kCaveMaxSize = 50;

class cave {
 public:
  void LoadCaveFromFile(std::string filename);
  void GenerateEmptyField(int height, int width);
  void update();

  void setBurthLimit(int n);
  void setdeathLimit(int n);
  void setFieldValue(int i, int j, int value);
  std::vector<std::vector<int>> getField() const;

 private:
  int x_size, y_size;
  int CalcNextStateOfCell(int x, int y);
  int burth_limit = 0;
  int death_limit = 0;
  std::vector<std::vector<int>> field;
};  // class cave

}  // namespace s21

#endif  // A1_MAZE_MODEL_CAVE_H
