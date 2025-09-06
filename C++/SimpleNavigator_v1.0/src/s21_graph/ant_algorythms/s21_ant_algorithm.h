#ifndef SIMPLE_NAVIGATOR_SRC_ANT_ALGORITHMS_S21_ANT_ALGORITHM_H
#define SIMPLE_NAVIGATOR_SRC_ANT_ALGORITHMS_S21_ANT_ALGORITHM_H

#include <vector>
#include <chrono>

#include "../s21_graph.h"

using matrix = std::vector<std::vector<double>>;

typedef struct TsmResult {
  std::vector<int> vertices;
  double distance = 0.0;
}TsmResult;



struct Ant {
  explicit Ant(int start_vertex = 0, std::size_t graphSize = 0)
      : start_location_(start_vertex), path_({std::vector<int>(graphSize, 0), 0.0}) {
    visited_.resize(graphSize, false);
  };

  int start_location_, current_location_ = 0;

  bool can_continue = true;

  TsmResult path_;

  std::vector<bool> visited_;
  void MakeChoice(const Graph &graph, const matrix &phers, double a, double b);
  double getRandomChoice();
  std::vector<int> getAccessibleNeighborsVertexes(const Graph &graph);
};

class AntAlgorithm {
public:
  explicit AntAlgorithm(const Graph &graph);
  AntAlgorithm(AntAlgorithm&& other) = delete;
  AntAlgorithm(AntAlgorithm& other) = delete;
  TsmResult SolveTravellingSalesmanProblem();

private:
  const double kAlpha_ = 1.0;
  const double kBeta_ = 2.0;
  const double kPheromone_ = 1.0;
  const double kQ_ = 100.0; // total pheromone deposited
  const double kEvaporation_ = 0.2;

  // const int numIterations_ = 50;
  // init with size of graph
  int numAnts_ = 0;

  const Graph &graph_;
  matrix pheromone_;

  std::vector<Ant> ants_;

  void CreateAnts(size_t);
  void ResetAnts();
  void UpdateGlobalPheromone(const matrix &localPheromone);
};

#endif