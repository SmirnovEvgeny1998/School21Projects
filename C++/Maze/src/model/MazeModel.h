#ifndef MAZEMODEL_H
#define MAZEMODEL_H
#include <array>
#include <fstream>
#include <iostream>
#include <list>
#include <random>
#include <sstream>
#include <stack>

class Maze {
 public:
  Maze(int height, int width);

  void EulerTheFourth(int, int);

  void import(std::string filename);
  void Export(std::string filename);

  int Height();

  int Width();

  std::vector<std::vector<int>> GetRWMatrix();
  std::vector<std::vector<int>> GetFMatrix();

  void PrintMatrix();

  std::list<std::pair<int, int>> Solve(int i_start, int j_start, int i_end,
                                       int j_end);

 private:
  std::list<std::pair<int, int>> FindNeighbors(int i, int j);

  int rnJesus();

  void appointID(int* ID, std::vector<int>* cellsSet);

  void raiseVerticalWalls(std::vector<int>* cellsSet, int layer);

  void raiseHorizontalWalls(std::vector<int>* cellsSet, int layer,
                            bool* downPass);

  void resetForTheNextLayer(std::vector<int>* cellsSet, int* layer);

  void lastLayer(std::vector<int>* cellsSet, int layer);

  std::vector<std::vector<int>> RightWallMatrix;
  std::vector<std::vector<int>> FlorMatrix;
  int MazeHeight;
  int MazeWidth;
};

#endif
