#include <iostream>
#include "grid.h"

using namespace std;

Grid::Grid() {}

Grid::~Grid() {  }

void Grid::clearGrid() { }

bool Grid::isWon() const { return won; }

void Grid::init(int n) {
}

void Grid::turnOn(int r, int c) {
  theGrid[r][c].setOn();
}

void Grid::toggle(int r, int c) {
  theGrid[r][c].toggle();
}

ostream &operator<<(ostream &out, const Grid &g) {
}

void Grid::printCells() const {
}

