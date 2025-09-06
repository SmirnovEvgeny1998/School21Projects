#include "../s21_graph/s21_graph.h"
#include "../s21_graph/s21_graph_algorithms.h"
#include <filesystem>
#include <ncurses.h>
#include <unistd.h>
namespace fs = std::filesystem;

void printMenu(WINDOW *menu_win, uint highlight,
               const std::vector<std::string> &menu_items);

void runAlgo(const Graph &graph, int choice);

std::vector<std::string> getFiles(const std::string &directory);

std::string getDirectoryFromUser(WINDOW *input_win);

WINDOW *createWindow(int width, int height, int startX, int startY);

void initNcurses();

void cleanupNcurses();

uint navigateMenu(WINDOW *menu_win, const std::vector<std::string> &files);

void processFileChoice(const std::string &file);

void executeAlgorithm(Graph &graph, uint choice);

int main() {
  initNcurses();

  WINDOW *input_win = createWindow(3, 50, (LINES - 3) / 2, (COLS - 50) / 2);

  std::string directory = getDirectoryFromUser(input_win);
  delwin(input_win);
  if (directory.empty()) {
    cleanupNcurses();
    std::cerr << "No directory provided" << std::endl;
    return EXIT_FAILURE;
  }

  std::string defaultPath = "./data/";

  // Directory where graph files are stored
  std::vector<std::string> files;

  WINDOW *menu_win = createWindow(20, 80, 0, 0);

  try {
    files = getFiles(directory);
  } catch (const fs::filesystem_error &e) {
    mvwprintw(menu_win, 2, 0, e.what());
    mvwprintw(menu_win, 5, 0, "using default dir:");
    mvwprintw(menu_win, 6, 0, defaultPath.c_str());
    wgetch(menu_win);
    directory = defaultPath;
    files = getFiles(defaultPath);
  }

  files.push_back("Exit");

  while (true) {
    uint fileChoice = navigateMenu(menu_win, files);
    if (files[fileChoice] == "Exit") {
      break;
    }
    processFileChoice(files[fileChoice]);
  }

  delwin(menu_win);
  endwin();

  return 0;
}

void initNcurses() {
  initscr();
  clear();
  noecho();
  cbreak();
  curs_set(0);
}

void cleanupNcurses() { endwin(); }

WINDOW *createWindow(int width, int height, int startX, int startY) {
  WINDOW *win = newwin(width, height, startX, startY);
  box(win, 0, 0);
  wrefresh(win);
  return win;
}

uint navigateMenu(WINDOW *menu_win, const std::vector<std::string> &files) {
  uint highlight = 1;
  uint choice = 0;
  int pressedKey = 0;

  keypad(menu_win, true);

  while (true) {
    printMenu(menu_win, highlight, files);
    pressedKey = wgetch(menu_win);
    switch (pressedKey) {
    case KEY_UP:
      if (highlight == 1)
        highlight = files.size();
      else
        --highlight;
      break;
    case KEY_DOWN:
      if (highlight == files.size())
        highlight = 1;
      else
        ++highlight;
      break;
    case 10: // Enter
      choice = highlight;
      break;
    default:
      break;
    }

    if (choice != 0) {
      return choice - 1;
    }
  }
}

void processFileChoice(const std::string &file) {
  Graph graph;
  try {
    graph.LoadGraphFromFile(file);
  } catch (const std::exception &e) {
    printw("Error loading graph from file %s\n", file.c_str());
    printw(e.what());
    refresh();
    getch();
    return;
  }

  WINDOW *menu_win = createWindow(20, 80, 0, 0);
  std::vector<std::string> algorithms = {"Depth First Search",
                                         "Breadth First Search",
                                         "Shortest Path Between Two Vertices",
                                         "Shortest Path Between All Vertices",
                                         "Minimum Spanning Tree",
                                         "Travelling Salesman Problem",
                                         "Back"};

  while (true) {
    erase();
    refresh();
    uint algoChoice = navigateMenu(menu_win, algorithms);
    if (algorithms[algoChoice] == "Back") {
      break;
    }
    try {
      executeAlgorithm(graph, algoChoice);
    } catch (const std::exception &e) {
      printw("Error executing algorithm %s\n Press any key to continue...",
             e.what());
      getch();
    }
  }

  delwin(menu_win);
}

std::string getDirectoryFromUser(WINDOW *input_win) {
  curs_set(1);
  echo();
  mvwprintw(input_win, 1, 0, "Directory: ");
  wrefresh(input_win);

  char directory[PATH_MAX];
  wgetnstr(input_win, directory, sizeof(directory) - 1);
  curs_set(0);
  noecho();
  auto dir = std::string(directory);
  return dir;
}

std::vector<std::string> getFiles(const std::string &directory) {
  std::vector<std::string> files;

  for (const auto &entry : fs::directory_iterator(directory)) {
    if (entry.is_regular_file()) {
      files.push_back(entry.path().string());
    }
  }

  return files;
}

void printMenu(WINDOW *menu_win, uint highlight,
               const std::vector<std::string> &menu_items) {
  wclear(menu_win);
  int x = 2, y = 2;
  box(menu_win, x, y);

  for (uint i = 0; i < menu_items.size(); i++) {
    if (highlight == i + 1) {
      wattron(menu_win, A_REVERSE);
      mvwprintw(menu_win, y, x, "%s", menu_items[i].c_str());
      wattroff(menu_win, A_REVERSE);
    } else {
      mvwprintw(menu_win, y, x, "%s", menu_items[i].c_str());
    }
    ++y;
  }
  wrefresh(menu_win);
}

void runBFS(Graph &graph) {
  int start_vertex;
  printw("Enter start vertex for Breadth First Search: ");
  char *s = const_cast<char *>("%d");
  scanw(s, &start_vertex);
  auto result = GraphAlgorithms::BreadthFirstSearch(graph, start_vertex);
  printw("Breadth First Search Result:\n");
  for (int vertex : result) {
    printw("%d ", vertex);
  }
}

void runDFS(Graph &graph) {
  int start_vertex;
  char *s = const_cast<char *>("%d");
  printw("Enter start vertex for Depth First Search: ");
  scanw(s, &start_vertex);
  auto result = GraphAlgorithms::DepthFirstSearch(graph, start_vertex);
  printw("Depth First Search Result:\n");
  for (int vertex : result) {
    printw("%d ", vertex);
  }
}

void runDijkstra(Graph &graph) {
  int vertex1, vertex2;
  // such magic tricks because default string is const
  char *s = const_cast<char *>("%d");
  printw("Enter start vertex: ");
  scanw(s, &vertex1);
  printw("Enter end vertex: ");
  scanw(s, &vertex2);
  double distance =
      GraphAlgorithms::GetShortestPathBetweenVertices(graph, vertex1, vertex2);
  printw("Shortest Path Between Vertex %d and %d is: %f\n", vertex1, vertex2,
         distance);
}

void runFloydWarshall(Graph &graph) {
  auto matrix = GraphAlgorithms::GetShortestPathBetweenAllVertices(graph);
  printw("Shortest Path Between All Vertices:\n");
  for (const auto &row : matrix) {
    for (double weight : row) {
      printw("%f ", weight);
    }
    printw("\n");
  }
}

void runPrim(Graph &graph) {
  auto mst = GraphAlgorithms::GetLeastSpanningTree(graph);
  printw("Minimum Spanning Tree:\n");
  for (const auto &row : mst) {
    for (double weight : row) {
      printw("%f ", weight);
    }
    printw("\n");
  }
}
void runAnt(Graph &graph) {
  auto result = GraphAlgorithms::SolveTravellingSalesmanProblem(graph);
  printw("Travelling Salesman Problem Result:\nVertices: ");
  for (int vertex : result.vertices) {
    printw("%d ", vertex);
  }
  printw("\nDistance: %f\n", result.distance);
}

void executeAlgorithm(Graph &graph, uint choice) {
  erase();
  refresh();
  echo();
  switch (choice) {
  case 0:
    runDFS(graph);
    break;
  case 1:
    runBFS(graph);
    break;
  case 2:
    runDijkstra(graph);
    break;
  case 3:
    runFloydWarshall(graph);
    break;
  case 4:
    runPrim(graph);
    break;
  case 5:
    runAnt(graph);
    break;
  default:
    break;
  }
  noecho();
  printw("\nAlgorithm Completed, press any key to continue...");
  refresh();
  getch();
}
