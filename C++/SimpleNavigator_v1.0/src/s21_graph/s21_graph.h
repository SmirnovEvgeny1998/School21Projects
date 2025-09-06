#ifndef SIMPLE_NAVIGATOR_SRC_S21_GRAPH_H
#define SIMPLE_NAVIGATOR_SRC_S21_GRAPH_H

#include <filesystem>
#include <fstream>
#include <limits>
#include <string>
#include <vector>

#ifndef INFINITY
#define INFINITY std::numeric_limits<double>::infinity()
#endif
// struct TsmResult {
//   std::vector<int>vertices;
//   double distance;
// };

class Graph {
public:
  using matrix = std::vector<std::vector<double>>;

  Graph() = default;
  Graph(const Graph &);
  ~Graph() = default;
  void LoadGraphFromFile(const std::string &filename);
  bool ExportGraphToDot(const std::string &filename);
  double GetWeight(int row, int col) const;
  int GetSize() const;
  void SetElem(int row, int col, double weight);
  matrix GetMatrix() const;

private:
  int size_ = 0;
  matrix adjMatrix_;
};

#endif
