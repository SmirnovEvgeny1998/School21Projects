#ifndef SIMPLE_NAVIGATOR_SRC_TESTS_S21_GRAPH_TEST_H
#define SIMPLE_NAVIGATOR_SRC_TESTS_S21_GRAPH_TEST_H

#include <vector>

#include <string>

const std::vector<std::vector<double>> adjMatrix = {
    {0, 29, 20, 21, 16, 31, 100, 12, 4, 31, 18},
    {29, 0, 15, 29, 28, 40, 72, 21, 29, 41, 12},
    {20, 15, 0, 15, 14, 25, 81, 9, 23, 27, 13},
    {21, 29, 15, 0, 4, 12, 92, 12, 25, 13, 25},
    {16, 28, 14, 4, 0, 16, 94, 9, 20, 16, 22},
    {31, 40, 25, 12, 16, 0, 95, 24, 36, 3, 37},
    {100, 72, 81, 92, 94, 95, 0, 90, 101, 99, 84},
    {12, 21, 9, 12, 9, 24, 90, 0, 15, 25, 13},
    {4, 29, 23, 25, 20, 36, 101, 15, 0, 35, 18},
    {31, 41, 27, 13, 16, 3, 99, 25, 35, 0, 35},
    {18, 12, 13, 25, 22, 37, 84, 13, 18, 35, 0}};

std::vector<std::vector<int>> graphAlgorithmBetweenAllResult = {
    {0, 1, 2, 3, 2},
    {1, 0, 3, 4, 1},
    {1, 2, 0, 4, 3},
    {1, 2, 3, 0, 1},
    {4, 4, 4, 7, 0}};

const std::string graphPath = "./data/graph.txt";
const int graphSize = 11;

const std::vector<std::vector<double>> graphAlgorithmLeastSpanningTreeResult = {
    {0, 0, 0, 0, 0, 0, 0, 12, 4, 0, 0}, {0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13}, {0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0},
    {0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0},  {0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  {0, 0, 9, 0, 9, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

#endif // SIMPLE_NAVIGATOR_SRC_TESTS_S21_GRAPH_TEST_H