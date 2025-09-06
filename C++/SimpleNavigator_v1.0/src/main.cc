#include "./s21_graph/s21_graph.h"

#include "./s21_graph/s21_graph_algorithms.h"
#include <iostream>

int main() {
  Graph graph;
  try {
    graph.LoadGraphFromFile("./data/graph.txt");
  } catch (const std::runtime_error &e) {
    std::cerr << e.what() << std::endl;
  }
  //  std::vector<int> res;
  // Graph::matrix res;
  // TsmResult res1;
  // try {
  //   // res = GraphAlgorithms::GetLeastSpanningTree(graph);
  //   res1 = GraphAlgorithms::SolveTravellingSalesmanProblem(graph);
  // } catch (std::out_of_range &e) {
  //   std::cout << e.what() << std::endl;
  // } catch (const std::runtime_error &e) {
  //   std::cout << e.what() << std::endl;
  // }

  // // for (auto i : res) {
  // //   for (auto j : i) {
  // std::cout << res1.distance << " ";
  // //   }
  //   std::cout << std::endl;
  // }
  return 0;
}
