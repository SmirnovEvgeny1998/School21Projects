#include "s21_graph_test.h"

#include "../s21_graph/s21_graph.h"
#include "../s21_graph/s21_graph_algorithms.h"
#include <gtest/gtest.h>

TEST(GraphTest, DefaultConstructor) {
  Graph graph;
  EXPECT_EQ(graph.GetSize(), 0);
}

TEST(GraphTest, LoadGraphFromFile_1) {
  Graph graph;
  EXPECT_NO_THROW(graph.LoadGraphFromFile(graphPath));
  EXPECT_EQ(graph.GetSize(), graphSize);
}

TEST(GraphTest, LoadGraphFromFile_2) {
  Graph graph;
  EXPECT_THROW(graph.LoadGraphFromFile("/usr/wrongpath.txt"),
               std::runtime_error);
}

TEST(GraphTest, LeadGraphFromFile_3) {
  Graph graph;
  EXPECT_THROW(graph.LoadGraphFromFile("./data/empty.txt"), std::runtime_error);
}

TEST(GraphTest, LeadGraphFromFile_4) {
  Graph graph;
  EXPECT_THROW(graph.LoadGraphFromFile("./data/fault_graph.txt"),
               std::runtime_error);
}

TEST(GraphTest, ExportGraphToDot_1) {
  Graph graph;
  EXPECT_NO_THROW(graph.LoadGraphFromFile(graphPath));
  EXPECT_NO_THROW(graph.ExportGraphToDot("./data/graph_test.dot"));
}

TEST(GraphTest, ExportGraphToDot_2) {
  Graph graph;
  EXPECT_NO_THROW(graph.LoadGraphFromFile(graphPath));
  EXPECT_FALSE(graph.ExportGraphToDot("./data/"));
}

TEST(GraphAlgorithmsTest, DFS_1) {
  Graph graph;
  graph.LoadGraphFromFile("./data/graph_for_paths.txt");
  std::vector<int> res;
  std::vector<int> answ = {4, 5, 3, 1, 2};
  EXPECT_NO_THROW(res = GraphAlgorithms::DepthFirstSearch(graph, 4));
  EXPECT_TRUE(res == answ);
}

TEST(GraphAlgorithmsTest, DFS_2) {
  Graph graph;
  EXPECT_THROW(GraphAlgorithms::DepthFirstSearch(graph, 1), std::logic_error);
}

TEST(GraphAlgorithmsTest, DFS_3) {
  Graph graph;
  graph.LoadGraphFromFile("./data/graph_for_paths.txt");
  EXPECT_THROW(GraphAlgorithms::DepthFirstSearch(graph, 14), std::out_of_range);
}

TEST(GraphAlgorithmsTest, BFS_1) {
  Graph graph;
  graph.LoadGraphFromFile("./data/graph_for_paths.txt");
  std::vector<int> res;
  std::vector<int> answ = {4, 1, 3, 5, 2};
  EXPECT_NO_THROW(res = GraphAlgorithms::BreadthFirstSearch(graph, 4));
  EXPECT_TRUE(res == answ);
}

TEST(GraphAlgorithmsTest, BFS_2) {
  Graph graph;
  EXPECT_THROW(GraphAlgorithms::BreadthFirstSearch(graph, 1), std::logic_error);
}

TEST(GraphAlgorithmsTest, BFS_3) {
  Graph graph;
  graph.LoadGraphFromFile("./data/graph_for_paths.txt");
  EXPECT_THROW(GraphAlgorithms::BreadthFirstSearch(graph, 14),
               std::out_of_range);
}

TEST(GraphAlgorithmsTest, GetShortestPathBetweenTwoVerticies_1) {
  Graph graph;
  graph.LoadGraphFromFile("./data/graph_for_paths.txt");
  EXPECT_EQ(GraphAlgorithms::GetShortestPathBetweenVertices(graph, 3, 5), 3);
}

TEST(GraphAlgorithmsTest, GetShortestPathBetweenTwoVerticies_2) {
  Graph graph;
  graph.LoadGraphFromFile("./data/graph_for_paths.txt");
  EXPECT_THROW(GraphAlgorithms::GetShortestPathBetweenVertices(graph, 10, 5),
               std::out_of_range);
}

TEST(GraphAlgorithmsTest, GetShortestPathBetweenAllVertices) {
  Graph graph;
  graph.LoadGraphFromFile("./data/graph_for_paths.txt");
  GraphAlgorithms::matrix mat;
  EXPECT_NO_THROW(
      mat = GraphAlgorithms::GetShortestPathBetweenAllVertices(graph));

  std::cout << "\n correct res \n";
  for (int i = 0; i < (int)mat.size(); i++) {
    for (int j = 0; j < (int)mat[i].size(); j++) {
      std::cout << graphAlgorithmBetweenAllResult[i][j] << " ";
    }
    std::cout << std::endl;
  }

  for (uint i = 0, len = mat.size(); i < len; ++i) {
    for (uint j = 0; j < len; ++j) {
      EXPECT_EQ(mat[i][j], graphAlgorithmBetweenAllResult[i][j]);
    }
  }
}

void printColored(int first, int second) {
  std::cout << first << " " << second << std::endl;
}

int PrintDiffMatrixes(matrix mat1, matrix mat2) {
  if (mat1.size() != mat2.size()) {
    return 1;
  }

  for (uint i = 0; i < mat1.size(); i++) {
    for (uint j = 0; j < mat1[i].size(); j++) {
      if (mat1[i][j] != mat2[i][j]) {
        printColored(mat1[i][j], mat2[i][j]);
      } else {
        std::cout << mat1[i][j] << " ";
      }
    }
  }

  return 0;
}

TEST(GraphAlgorithmTest, GetLeastSpanningTree_1) {
  Graph graph;
  graph.LoadGraphFromFile("./data/graph.txt");

  GraphAlgorithms::matrix mat;
  EXPECT_NO_THROW(mat = GraphAlgorithms::GetLeastSpanningTree(graph));

  // TODO: make function which will accept two matrix and print diff with colors
  std::cout << "\n correct res \n";
  for (const auto &i : graphAlgorithmLeastSpanningTreeResult) {
    for (double j : i) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }

  std::cout << "\n myres res \n";
  for (int i = 0; i < (int)mat.size(); i++) {
    for (int j = 0; j < (int)mat[i].size(); j++) {
      std::cout << mat[i][j] << " ";
    }
    std::cout << std::endl;
  }

  for (uint i = 0, len = mat.size(); i < len; ++i) {
    for (uint j = 0; j < len; ++j) {
      EXPECT_EQ(mat[i][j], graphAlgorithmLeastSpanningTreeResult[i][j]);
    }
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
