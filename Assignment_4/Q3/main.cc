#include <iostream>
#include <string>
#include "grid.h"

using namespace std;

int main() {
  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd, aux;
  Grid g;
  int moves = 0;

  // You will need to make changes this code.

  while (true) {
    cin >> cmd;
    if (cmd == "new") {
      int n;
      cin >> n;
    }
    else if (cmd == "init") {
      cout << g;
    }
    else if ( cmd == "neighbours" ) {
      g.printCells();
    }
    else if (cmd == "game") {
      cin >> moves;
    }
    else if (cmd == "switch") {
      int r = 0, c = 0;
      cin >> r >> c;
    }
  }
}

