#include "MazeController.h"

/**
 @brief Загрузить Maze из фаила
 @param filename - путь/имя фаила
 */
void MazeController::LoadMaze(std::string filename) { maze_->import(filename); }

/**
 @brief Сохранить Maze в фаиле
 @param filename - путь/имя фаила
 */
void MazeController::ExportMaze(std::string filename) {
  maze_->Export(filename);
}

/**
 @brief Генерация лабиринта с заданными параметрами
 @param width - ширина генерируемого лабиринта
 @param height - высота генерируемого лабиринта
 */
void MazeController::GenerateMaze(int height, int width) {
  maze_->EulerTheFourth(height, width);
}

/**
 @brief Возвращает путь между двумя точками в лабиринте
 @param j_start - номер ряда матрицы отправной точки
 @param i_start - номер столбца матрицы отправной точки
 @param j_end - номер ряда матрицы конечной точки
 @param i_end - номер столбца матрицы конечной точки
 */
std::list<std::pair<int, int>> MazeController::SolveMaze(int start_x,
                                                         int start_y,
                                                         int finish_x,
                                                         int finish_y) {
  return maze_->Solve(start_x, start_y, finish_x, finish_y);
}

/**
 @brief Возвращает информацию о лабиринте: ширину, высоту, матрицу правой стены,
 матрицу нижней стены
 */
const MazeController::MazeInfo MazeController::GetMazeInfo() {
  MazeInfo inf;
  inf.maze_height = maze_->Height();
  inf.maze_width = maze_->Width();
  inf.RWMatrix = maze_->GetRWMatrix();
  inf.FMatrix = maze_->GetFMatrix();
  ;
  return inf;
}
