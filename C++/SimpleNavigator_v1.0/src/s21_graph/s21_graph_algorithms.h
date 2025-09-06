#ifndef SIMPLE_NAVIGATOR_SRC_S21_GRAPH_ALGORITHMS_H
#define SIMPLE_NAVIGATOR_SRC_S21_GRAPH_ALGORITHMS_H

#include "s21_graph.h"
#include <vector>

#include "../queue/s21_queue.h"
#include "../stack/s21_stack.h"
#include "./ant_algorythms/s21_ant_algorithm.h"

class GraphAlgorithms {
public:
  using matrix = Graph::matrix;

public:
  GraphAlgorithms() = default;
  ~GraphAlgorithms();

public:
  static std::vector<int> DepthFirstSearch(Graph &graph, int start_vertex);
  static std::vector<int> BreadthFirstSearch(Graph &graph, int start_vertex);
  static double GetShortestPathBetweenVertices(Graph &graph, int start,
                                               int end);
  static matrix GetShortestPathBetweenAllVertices(Graph &graph);
  static matrix GetLeastSpanningTree(const Graph &graph);
  static TsmResult SolveTravellingSalesmanProblem(const Graph &graph);
};

void printAdjMat(const Graph &graph);

#endif