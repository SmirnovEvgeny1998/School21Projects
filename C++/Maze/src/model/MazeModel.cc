#include "MazeModel.h"

#include <array>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <stack>
#include <string>

/**
 @brief Конструктор  класса Maze
 @param width - ширина генерируемого лабиринта
 @param height - высота генерируемого лабиринта
 */
Maze::Maze(int height, int width) {
  if (height > 50 || height < 2) {
    height = 10;
  }
  if (width > 50 || width < 2) {
    width = 10;
  }
  MazeHeight = height;
  MazeWidth = width;
  RightWallMatrix.resize(height, std::vector<int>(width, 1));
  FlorMatrix.resize(height, std::vector<int>(width, 1));
}

/**
 @brief Создает лабиринт случайным образом согласно заданным параметрам
 @param width - ширина генерируемого лабиринта
 @param height - высота генерируемого лабиринта
 */
void Maze::EulerTheFourth(int height, int width) {
  int ID = 0, layer = 0;
  bool downPass = false;
  std::vector<int> cellsSet(50, -1);
  if (height > 50 || height < 2) {
    height = 10;
  }
  if (width > 50 || width < 2) {
    width = 10;
  }
  MazeHeight = height;
  MazeWidth = width;
  RightWallMatrix.resize(height, std::vector<int>(width, 1));
  FlorMatrix.resize(height, std::vector<int>(width, 1));
  for (int i = 0; i < height; i++) {
    FlorMatrix[i].resize(width, 1);
    RightWallMatrix[i].resize(width, 1);
  }
  while (layer != MazeHeight - 1) {
    appointID(&ID, &cellsSet);
    raiseVerticalWalls(&cellsSet, layer);
    raiseHorizontalWalls(&cellsSet, layer, &downPass);
    resetForTheNextLayer(&cellsSet, &layer);
    if (layer == MazeHeight - 1) {
      appointID(&ID, &cellsSet);
      lastLayer(&cellsSet, layer);
    }
  }
}

/**
 @brief Импортирует лабиринт из фаила
 @param filename - путь к фаилу и его имя
 */
void Maze::import(std::string filename) {
  char temp;
  std::string line;
  std::ifstream in;
  in.open(filename);
  if (in.is_open()) {
    std::getline(in, line);
    std::stringstream ss(line);
    std::string word;
    ss >> word;
    MazeHeight = std::stoi(word);
    ss >> word;
    MazeWidth = std::stoi(word);
    RightWallMatrix.resize(MazeHeight, std::vector<int>(MazeWidth, 1));
    FlorMatrix.resize(MazeHeight, std::vector<int>(MazeWidth, 1));
    for (int i = 0; i < MazeHeight; i++) {
      FlorMatrix[i].resize(MazeWidth, 1);
      RightWallMatrix[i].resize(MazeWidth, 1);
    }
    for (int i = 0; i < MazeHeight; i++) {
      for (int j = 0; j < MazeWidth; j++) {
        in >> temp;
        RightWallMatrix[i][j] = temp - '0';
      }
    }
    for (int i = 0; i < MazeHeight; i++) {
      for (int j = 0; j < MazeWidth; j++) {
        in >> temp;
        FlorMatrix[i][j] = temp - '0';
      }
    }
  } else {
    throw std::invalid_argument("Error occurred while opening file...");
  }
  in.close();
}

/**
 @brief Сохраняет лабиринт в фаиле
 @param filename - путь к фаилу и его имя
 */
void Maze::Export(std::string filename) {
  std::ofstream out;
  out.open(filename);
  if (out.is_open()) {
    out << MazeHeight << " " << MazeWidth << "\n";
    for (int i = 0; i < MazeHeight; i++) {
      for (int j = 0; j < MazeWidth; j++) {
        out << RightWallMatrix[i][j];
      }
      out << "\n";
    }
    out << "\n";
    for (int i = 0; i < MazeHeight; i++) {
      for (int j = 0; j < MazeWidth; j++) {
        out << FlorMatrix[i][j];
      }
      out << "\n";
    }
    out.close();
  } else {
    throw std::invalid_argument("Error occurred while creating file...");
  }
}

/**
 @brief Выводит в терминал упрощенное представление лабиринта
 */
void Maze::PrintMatrix() {
  std::cout << MazeHeight << MazeWidth << "\n";
  for (int i = 0; i < MazeHeight; i++) {
    for (int j = 0; j < MazeWidth; j++) {
      std::cout << RightWallMatrix[i][j];
    }
    std::cout << "\n";
  }
  std::cout << "\n";
  for (int i = 0; i < MazeHeight; i++) {
    for (int j = 0; j < MazeWidth; j++) {
      std::cout << FlorMatrix[i][j];
    }
    std::cout << "\n";
  }
  std::cout << "\n";
  for (int j = 0; j < MazeWidth * 2; j++) {
    std::cout << "_";
  }
  std::cout << "\n";
  for (int i = 0; i < MazeHeight; i++) {
    for (int j = 0; j < MazeWidth; j++) {
      if (FlorMatrix[i][j] == 1) {
        std::cout << "_";
      } else {
        std::cout << " ";
      }
      if (RightWallMatrix[i][j] == 1) {
        std::cout << "|";
      } else {
        std::cout << " ";
      }
    }
    std::cout << "\n";
  }
}

/**
 @brief Возвращает высоту лабиринта
 */
int Maze::Height() { return MazeHeight; }

/**
 @brief Возвращает ширину лабиринта
 */
int Maze::Width() { return MazeWidth; }

/**
 @brief Возвращает матрицу отображения правых стен ячеек  лабиринта
 */
std::vector<std::vector<int>> Maze::GetRWMatrix() { return RightWallMatrix; }

/**
 @brief Возвращает матрицу отображения нижних стен ячеек лабиринта
 */
std::vector<std::vector<int>> Maze::GetFMatrix() { return FlorMatrix; }

/**
 @brief Возвращает путь между двумя точками в лабиринте
 @param j_start - номер ряда матрицы отправной точки
 @param i_start - номер столбца матрицы отправной точки
 @param j_end - номер ряда матрицы конечной точки
 @param i_end - номер столбца матрицы конечной точки
 */
std::list<std::pair<int, int>> Maze::Solve(int j_start, int i_start, int j_end,
                                           int i_end) {
  std::queue<std::pair<int, int>> neighbors;
  std::map<std::pair<int, int>, bool> visited;
  std::map<std::pair<int, int>, std::pair<int, int>> prev;

  std::pair<int, int> start(i_start, j_start);
  std::pair<int, int> finish(i_end, j_end);

  std::list<std::pair<int, int>> path;
  neighbors.push(start);
  while (!neighbors.empty()) {
    std::pair<int, int> n = neighbors.front();
    neighbors.pop();
    for (auto v : FindNeighbors(n.first, n.second)) {
      if (visited.find(v) == visited.end()) {
        prev[v] = n;
        if (v == finish) {
          while (prev.find(v) != prev.end()) {
            path.push_back(v);
            // std::cout << "N:" << v.first << " " << v.second << std::endl;
            v = prev[v];
          }
          path.push_back(start);
          return path;
        } else {
          neighbors.push(v);
          visited[n] = true;
        }
      }
    }
  }
  return path;
}

/**
 @brief Возвращает координаты ячеек в которые можно напрямую попасть из нынешних
 координат
 @param j - номер ряда матрицы
 @param i - номер столбца матрицы
 */
std::list<std::pair<int, int>> Maze::FindNeighbors(int i, int j) {
  std::list<std::pair<int, int>> neighbors;
  if (i - 1 >= 0 && FlorMatrix[i - 1][j] != 1) {
    neighbors.push_back(std::pair(i - 1, j));
  }
  if (i + 1 < MazeHeight && FlorMatrix[i][j] != 1) {
    neighbors.push_back(std::pair(i + 1, j));
  }
  if (j - 1 >= 0 && RightWallMatrix[i][j - 1] != 1) {
    neighbors.push_back(std::pair(i, j - 1));
  }
  if (j + 1 < MazeWidth && RightWallMatrix[i][j] != 1) {
    neighbors.push_back(std::pair(i, j + 1));
  }
  return neighbors;
}

/**
 @brief Генерирует случайным образом и возвращает 0 или 1
 */
int Maze::rnJesus() {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> CoinToss(0, 1);
  return CoinToss(rng);
}

/**
 @brief Дает ряду ячеек лабиринта идентефикаторы для использования алгоритма
 создания
 @param *ID - ссылка на переменную дающую новый ID "пустым" клеткам(равным -1)
 @param cellsSet - ряд ячеек лабиринта для заполнения
 */
void Maze::appointID(int* ID, std::vector<int>* cellsSet) {
  for (int i = 0; i < MazeWidth; i++) {
    if (cellsSet[0][i] == -1) {
      cellsSet[0][i] = *ID;
      *ID += 1;
    }
  }
}

/**
 @brief Создает вертикальные стены в лабиринте и заполняет матрицу правой стены
 @param layer - ряд лабиринта
 @param cellsSet - ряд ячеек лабиринта для заполнения
 */
void Maze::raiseVerticalWalls(std::vector<int>* cellsSet, int layer) {
  for (int i = 0; i < MazeWidth; i++) {
    if (i != MazeWidth - 1 && cellsSet[0][i] != cellsSet[0][i + 1] &&
        rnJesus() == 0) {
      int temp = cellsSet[0][i + 1];
      RightWallMatrix[layer][i] = 0;
      for (int j = 0; j < MazeWidth; j++) {
        if (cellsSet[0][j] == temp) {
          cellsSet[0][j] = cellsSet[0][i];
        }
      }
    } else {
      RightWallMatrix[layer][i] = 1;
    }
  }
}

/**
 @brief Создает вертикальные стены в лабиринте и заполняет матрицу нижней стены
 @param layer - ряд лабиринта
 @param cellsSet - ряд ячеек лабиринта для заполнения
 @param downPass - флаг отражающий имеет ли данный "сет" ячеек путь вниз
 */
void Maze::raiseHorizontalWalls(std::vector<int>* cellsSet, int layer,
                                bool* downPass) {
  for (int i = 0; i < MazeWidth; i++) {
    if (i == MazeWidth - 1 && *downPass == false) {
      FlorMatrix[layer][i] = 0;
    } else if (cellsSet[0][i] != cellsSet[0][i + 1] && *downPass == false) {
      FlorMatrix[layer][i] = 0;
    } else if (cellsSet[0][i] != cellsSet[0][i + 1]) {
      FlorMatrix[layer][i] = rnJesus();
      *downPass = false;
    } else {
      FlorMatrix[layer][i] = rnJesus();
      if (FlorMatrix[layer][i] == 0) {
        *downPass = true;
      }
    }
  }
}

/**
 @brief Стирает заполненные данные предыдущего ряда для продолжения работы
 алгоритма в следующем
 @param layer - ряд лабиринта
 @param cellsSet - ряд ячеек лабиринта для заполнения
 */
void Maze::resetForTheNextLayer(std::vector<int>* cellsSet, int* layer) {
  for (int i = 0; i < MazeWidth; i++) {
    if (FlorMatrix[*layer][i] == 1) {
      cellsSet[0][i] = -1;
    }
  }
  *layer += 1;
}

/**
 @brief Обрабатывает создание последнего ряда лабиринта
 @param layer - ряд лабиринта
 @param cellsSet - ряд ячеек лабиринта для заполнения
 */
void Maze::lastLayer(std::vector<int>* cellsSet, int layer) {
  for (int i = 0; i < MazeWidth; i++) {
    if (i != MazeWidth - 1 && cellsSet[0][i] != cellsSet[0][i + 1]) {
      int temp = cellsSet[0][i + 1];
      RightWallMatrix[layer][i] = 0;
      for (int j = 0; j < MazeWidth; j++) {
        if (cellsSet[0][j] == temp) {
          cellsSet[0][j] = cellsSet[0][i];
        }
      }
    } else {
      RightWallMatrix[layer][i] = 1;
    }
  }
}
