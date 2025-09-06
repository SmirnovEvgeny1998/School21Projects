#include "s21_graph_algorithms.h"

#include <queue>

std::vector<int> GraphAlgorithms::DepthFirstSearch(Graph &graph,
                                                   int start_vertex) {
  // assuming vertices start from 1 need to decrement to avoid segfault
  if (graph.GetSize() < 1) {
    throw std::logic_error("empty graph");
  }

  start_vertex--;
  std::vector<bool> visited(graph.GetSize(), false);
  std::vector<int> result;
  s21::stack<int> frontier;

  frontier.Push(start_vertex);
  visited[start_vertex] = true;
  result.push_back(start_vertex + 1);

  while (!frontier.Empty()) {
    int vertex = frontier.Top();
    frontier.Pop();

    for (int i = graph.GetSize() - 1; i >= 0; --i) {
      double weight = graph.GetWeight(vertex, i);
      if (!visited[i] && weight != INFINITY && abs(weight) > 0.e6) {
        frontier.Push(i);
        visited[i] = true;
        result.push_back(i + 1);
      }
    }
  }

  return result;
}

std::vector<int> GraphAlgorithms::BreadthFirstSearch(Graph &graph,
                                                     int start_vertex) {
  if (graph.GetSize() < 1) {
    throw std::logic_error("empty graph");
  }

  start_vertex--;
  std::vector<bool> visited(graph.GetSize(), false);
  std::vector<int> result;
  s21::queue<int> frontier;

  frontier.Push(start_vertex);
  visited[start_vertex] = true;
  result.push_back(start_vertex + 1);

  while (!frontier.Empty()) {
    int vertex = frontier.Front();
    frontier.Pop();

    for (int i = 0, len = graph.GetSize(); i < len; i++) {
      double weight = graph.GetWeight(vertex, i);
      if (!visited[i] && weight != INFINITY && abs(weight) > 0.e6) {
        frontier.Push(i);
        visited[i] = true;
        result.push_back(i + 1);
      }
    }
  }

  return result;
}
// better to use iterators
int minDistance(const std::vector<double> &dist,
                const std::vector<bool> &visited) {
  double min = INFINITY;
  int min_index = -1;

  for (int v = 0, len = (int)dist.size(); v < len; v++) {
    if (!visited[v] && dist[v] <= min) {
      min = dist[v], min_index = v;
    }
  }

  return min_index;
}

double GraphAlgorithms::GetShortestPathBetweenVertices(Graph &graph, int start,
                                                       int end) {
  auto size = graph.GetSize();
  if (size < 1) {
    throw std::logic_error("empty graph");
  } else if (start - 1 >= size || end - 2 >= size) {
    throw std::out_of_range("vertex if out of graph range");
  }

  std::vector<double> dist(graph.GetSize(), INFINITY);
  std::vector<bool> visited(graph.GetSize(), false);

  dist[start - 1] = 0;

  for (int i = 0, len = graph.GetSize(); i < len - 1; i++) {
    // better use min-priority queue for this one
    int u = minDistance(dist, visited);
    visited[u] = true;

    for (int v = 0, l = graph.GetSize(); v < l; v++) {
      double weight = graph.GetWeight(u, v);
      if (!visited[v] && abs(weight) > 0.e6 && dist[u] != INFINITY &&
          dist[u] + weight < dist[v]) {
        dist[v] = dist[u] + weight;
      }
    }
  }

  return dist[end - 1];
}

void printAdjMat(const Graph &graph) {
  auto mat = graph.GetMatrix();

  for (auto i : mat) {
    for (auto j : i) {
      std::cout << j << " ";
    }
    std::cout << "\n";
  }
}

Graph::matrix GraphAlgorithms::GetShortestPathBetweenAllVertices(Graph &graph) {
  if (graph.GetSize() < 1) {
    throw std::logic_error("empty graph");
  }

  const int n = graph.GetSize();
  Graph D(graph);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j == i) {
        D.SetElem(i, j, 0.);
      }
    }
  }
  std::cout << "\n";
  printAdjMat(D);
  // TODO: check with breakpoint when k is in shortest path
  // current implementation does not find shortest path for a one pair of
  // vertexes in test graph

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        double weightItoJ = D.GetWeight(i, j);
        double weightItoK = D.GetWeight(i, k);
        double weightKtoJ = D.GetWeight(k, j);
        if (weightKtoJ != INFINITY && weightItoK != INFINITY &&
            weightItoJ > weightItoK + weightKtoJ) {
          D.SetElem(i, j, weightItoK + weightKtoJ);
        }
      }
    }
  }

  std::cout << "\n";
  printAdjMat(D);
  return D.GetMatrix();
}

GraphAlgorithms::matrix
GraphAlgorithms::GetLeastSpanningTree(const Graph &graph) {
  auto GCopy(graph);
  if (GCopy.GetSize() < 1) {
    throw std::logic_error("empty graph");
  }

  constexpr int src = 0;
  const int n = GCopy.GetSize();

  std::vector<double> key(n, INFINITY);
  std::vector parent(n, -1);
  std::vector inMst(n, false);

  // TODO: refacor: make init func for empty matrix
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (GCopy.GetWeight(i, j) == INFINITY) {
        GCopy.SetElem(i, j, 0.);
      }
    }
  }

  // pq.push({0, src});
  printAdjMat(GCopy);
  key[src] = 0;
  for (int i = 0; i < n; i++) {
    int u = minDistance(key, inMst);

    if (inMst[u] == true) {
      continue;
    }
    inMst[u] = true;
    for (int v = 0; v < n; v++) {
      double weight = GCopy.GetWeight(u, v);
      if (inMst[v] == false && weight < key[v] && abs(weight) > 0.e6) {
        key[v] = weight;
        parent[v] = u;
      }
    }
  }

  matrix mst(n, std::vector<double>(n, 0.0));

  for (int i = 1; i < n; i++) {
    const int u = parent[i], v = i;
    mst[u][v] = GCopy.GetWeight(u, v);
    // mst[v][u] = D.GetWeight(u, v);
  }

  return mst;
}

TsmResult GraphAlgorithms::SolveTravellingSalesmanProblem(const Graph &graph) {
  if (graph.GetSize() < 1) {
    throw std::logic_error("empty graph");
  }
  auto solver = AntAlgorithm(graph);
  return solver.SolveTravellingSalesmanProblem();
}
