#include <gtest/gtest.h>

#include "../model/MazeModel.h"

TEST(maze, all) {
  Maze maze(10, 10);
  // maze.PrintMatrix();
  ASSERT_EQ(maze.Height(), 10);
  ASSERT_EQ(maze.Width(), 10);
  maze.EulerTheFourth(15, 32);
  ASSERT_EQ(maze.Height(), 15);
  ASSERT_EQ(maze.Width(), 32);
  maze.import("./tests/maze_example.txt");

  std::vector<std::vector<int>> matrix_r;
  std::vector<int> temp{0, 0, 0, 1};
  matrix_r.push_back(temp);
  temp = {1, 0, 1, 1};
  matrix_r.push_back(temp);
  temp = {0, 1, 0, 1};
  matrix_r.push_back(temp);
  temp = {0, 0, 0, 1};
  matrix_r.push_back(temp);
  std::vector<std::vector<int>> result_r = maze.GetRWMatrix();
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ASSERT_EQ(matrix_r[i][j], result_r[i][j]);
    }
  }

  std::vector<std::vector<int>> matrix_f;
  temp = {1, 0, 1, 0};
  matrix_f.push_back(temp);
  temp = {0, 0, 1, 0};
  matrix_f.push_back(temp);
  temp = {1, 1, 0, 1};
  matrix_f.push_back(temp);
  temp = {1, 1, 1, 1};
  matrix_f.push_back(temp);
  std::vector<std::vector<int>> result_f = maze.GetFMatrix();
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ASSERT_EQ(matrix_f[i][j], result_f[i][j]);
    }
  }

  std::list<std::pair<int, int>> result_solve;
  result_solve.push_back(std::pair(3, 3));
  result_solve.push_back(std::pair(3, 2));
  result_solve.push_back(std::pair(2, 2));
  result_solve.push_back(std::pair(2, 3));
  result_solve.push_back(std::pair(1, 3));
  result_solve.push_back(std::pair(0, 3));
  result_solve.push_back(std::pair(0, 2));
  result_solve.push_back(std::pair(0, 1));
  result_solve.push_back(std::pair(0, 0));
  ASSERT_EQ(maze.Solve(0, 0, 3, 3), result_solve);
}
