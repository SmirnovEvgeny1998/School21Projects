#include "s21_graph.h"

#include <iostream>
#include <vector>

Graph::Graph(const Graph &other) {
  size_ = other.size_;

  adjMatrix_ = other.adjMatrix_;
}

void Graph::LoadGraphFromFile(const std::string &filename) {
  std::ifstream in(filename, std::ios_base::in);

  if (!in.is_open()) {
    // not sure if this is an optimal way to handle such errors
    throw std::runtime_error("Could not open file " + filename);
  }

  in >> size_;

  if (size_ < 1) {
    size_ = 0;
    throw std::runtime_error("Graph size must be greater than 0");
  }

  auto mat = matrix(size_, std::vector<double>(size_));

  for (int i = 0; i < size_; i++) {
    for (int j = 0; j < size_; j++) {
      if (in.fail()) {
        size_ = 0;
        throw std::runtime_error("Error reading elem from file" + filename);
      }
      // std::cout << "i = " << i << " j = " << j << " val: ";
      double weight;
      in >> weight;
      if (weight == 0) {
        mat[i][j] = INFINITY;
      } else {
        mat[i][j] = weight;
      }
    }
  }
  adjMatrix_ = std::move(mat);
  in.close();
}

bool Graph::ExportGraphToDot(const std::string &filename) {
  if (adjMatrix_.empty())
    return false;

  std::ofstream file;
  file.open(filename);

  if (!file.is_open()) {
    return false;
  }

  std::filesystem::path filePath = filename;
  std::string name = filePath.stem().string();

  file << "digraph " << name << " {\n";
  for (int i = 0; i < size_; ++i) {
    for (int j = 0; j < size_; ++j) {
      if (adjMatrix_[i][j] != 0) {
        file << " " << static_cast<char>('a' + i) << " -- "
             << static_cast<char>('a' + j) << " [weight=\"" << adjMatrix_[i][j]
             << "\"];\n";
      }
    }
  }
  file << "}";

  file.close();
  return true;
}

int Graph::GetSize() const { return size_; }

void Graph::SetElem(int row, int col, double weight) {
  if (row < 0 || col < 0 || row >= size_ || col >= size_) {
    throw std::out_of_range("Index is out of range: " + std::to_string(row) +
                            std::string(",") + std::to_string(col));
  }

  if (adjMatrix_.empty()) {
    throw std::logic_error("Graph is empty");
  }

  adjMatrix_[row][col] = weight;
}

Graph::matrix Graph::GetMatrix() const { return adjMatrix_; }

double Graph::GetWeight(int row, int col) const {
  if (row < 0 || col < 0 || row >= size_ || col >= size_) {
    throw std::out_of_range("Index is out of range: " + std::to_string(row) +
                            std::string(",") + std::to_string(col));
  }

  if (adjMatrix_.empty() || size_ == 0) {
    throw std::logic_error("Graph is empty");
  }

  return adjMatrix_[row][col];
}
