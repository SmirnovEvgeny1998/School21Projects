#ifndef MAZECONTROLLER_H
#define MAZECONTROLLER_H
#include "../model/MazeModel.h"

class MazeController {
 public:
  struct MazeInfo {
    int maze_height;
    int maze_width;
    std::vector<std::vector<int>> RWMatrix;
    std::vector<std::vector<int>> FMatrix;
    MazeInfo &operator=(const MazeInfo &other) {
      maze_height = other.maze_height;
      maze_width = other.maze_width;
      RWMatrix = other.RWMatrix;
      FMatrix = other.FMatrix;
      return *this;
    }
  };
  MazeController(Maze *m) : maze_(m){};
  void LoadMaze(std::string filename);
  void ExportMaze(std::string filename);
  void GenerateMaze(int height, int width);
  std::list<std::pair<int, int>> SolveMaze(int start_x, int start_y,
                                           int finish_x, int finish_y);
  const MazeInfo GetMazeInfo();

 private:
  Maze *maze_;
};

#endif
