#include "s21_ant_algorithm.h"

#include <iostream>
#include <random>

AntAlgorithm::AntAlgorithm(const Graph &graph) : graph_(graph) {
  numAnts_ = graph.GetSize();
  matrix m(numAnts_, std::vector<double>(numAnts_, 0.0));

  for (int i = 0; i < numAnts_; i++)
    for (int j = 0; j < numAnts_; j++)
      m[i][j] = kPheromone_;

  pheromone_ = std::move(m);
}

void AntAlgorithm::CreateAnts(size_t graphSize) {
  ants_.resize(numAnts_);
  // Better to not create ant each
  for (int i = 0; i < numAnts_; i++) {
    ants_[i] = Ant(i, graphSize);
  }
}

void AntAlgorithm::ResetAnts() {
  if (ants_.empty()) {
    return;
  }

  for (int i = 0, size = static_cast<int>(ants_.size()); i < size; ++i) {
    ants_[i].can_continue = true;
    ants_[i].current_location_ = i;
    ants_[i].path_.vertices.clear();
    ants_[i].path_.distance = 0.0;
    ants_[i].visited_.clear();
  }
}

void AntAlgorithm::UpdateGlobalPheromone(const matrix &localPheromone) {
  for (int i = 0, len = numAnts_; i < len; ++i) {

    for (int j = 0; j < numAnts_; ++j) {
      pheromone_[i][j] =
          (1 - kEvaporation_) * pheromone_[i][j] + localPheromone[i][j];
      if (pheromone_[i][j] < 0.01 && i != j) {
        pheromone_[i][j] = 0.01;
      }
    }
  }
}

TsmResult AntAlgorithm::SolveTravellingSalesmanProblem() {
  if (graph_.GetSize() != numAnts_) {
    return {};
  }

  size_t maxIterWithoutImproving = 50;
  size_t numOfVertices = graph_.GetSize();
  std::size_t counter = 0;
  // std::size_t iter = 0;
  TsmResult path;
  path.distance = INFINITY;

  CreateAnts(numOfVertices);

  while (counter++ < maxIterWithoutImproving) {
    // iter++;
    matrix localPheromone(numOfVertices,
                          std::vector<double>(numOfVertices, 0.0));
    ResetAnts();

    for (auto &ant : ants_) {
      while (ant.can_continue) {
        ant.MakeChoice(graph_, pheromone_, kAlpha_, kBeta_);
        // std::cout << "making choice " << ant.current_location_ << std::endl;
      }

      auto ant_path = ant.path_;

      if (ant_path.vertices.size() == numOfVertices + 1) {
        if (path.distance > ant_path.distance) {
          path.vertices = ant_path.vertices;
          path.distance = ant_path.distance;
          counter = 0;
        }

        for (std::size_t v = 0, len = ant_path.vertices.size() - 1; v != len;
             ++v) {
          localPheromone[ant_path.vertices[v]][ant_path.vertices[v + 1]] =
              kQ_ / ant_path.distance;
        }
      }
    }
    UpdateGlobalPheromone(localPheromone);
  }
  // std::cout << "iter = " << iter << std::endl;
  return path;
}

double Ant::getRandomChoice() {
  std::uniform_real_distribution<double> dist(0, 1);
  std::default_random_engine generator(
      std::chrono::system_clock::now().time_since_epoch().count());
  return dist(generator);
}

std::vector<int> Ant::getAccessibleNeighborsVertexes(const Graph &graph) {
  std::vector<int> vertexes;
  for (int i = 0, len = graph.GetSize(); i < len; i++) {
    bool edgeExists = abs(graph.GetWeight(current_location_, i)) > 0.e6;
    bool vertexVisited = visited_[i];
    if (edgeExists && !vertexVisited) {
      vertexes.push_back(i);
    }
  }

  return vertexes;
}

void Ant::MakeChoice(const Graph &graph, const Graph::matrix &p, double alpha,
                     double beta) {

  if (path_.vertices.empty()) {
    path_.vertices.push_back(current_location_);
    visited_[current_location_] = true;
  }

  std::vector<int> neighbors = getAccessibleNeighborsVertexes(graph);

  if (neighbors.empty()) {
    // std::cout << "neighbors is empty" << std::endl;
    can_continue = false;
    if (graph.GetWeight(current_location_, start_location_) != 0.0) {
      path_.vertices.push_back(start_location_);
      path_.distance += graph.GetWeight(current_location_, start_location_);
    }
    return;
  }
  std::vector<double> probabilitiesToVisitNeighbor(neighbors.size());

  std::vector<double> wish;
  std::vector<double> probability;

  double summary_wish = 0.0;

  for (auto v : neighbors) {
    double t = p[current_location_][v];
    double w = graph.GetWeight(current_location_, v);
    double n = 1 / w;

    wish.push_back(std::pow(t, alpha) * std::pow(n, beta));
    summary_wish += wish.back();
  }

  for (std::size_t i = 0, len = neighbors.size(); i < len; i++) {
    double prob = (wish[i] / summary_wish);
    if (i == 0) {
      probabilitiesToVisitNeighbor[i] = prob;
    } else {
      probabilitiesToVisitNeighbor[i] =
          probabilitiesToVisitNeighbor[i - 1] + prob;
    }
  }

  std::size_t next_vertex = 0;
  double randomNeighborProbability = getRandomChoice();

  for (std::size_t i = 0, len = neighbors.size(); i < len; i++) {
    if (randomNeighborProbability <= probabilitiesToVisitNeighbor[i]) {
      next_vertex = neighbors[i];
      break;
    }
  }

  path_.vertices.push_back(next_vertex);
  path_.distance += graph.GetWeight(current_location_, next_vertex);
  visited_[next_vertex] = true;
  current_location_ = next_vertex;
}
