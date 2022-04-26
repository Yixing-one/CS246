#include "lifegame.h"

void LifeGame::play() {
    char cmd;
    int x, y;
    int N;
    while (cin >> cmd) {
        switch (cmd) {
            case 'u':
                // Update to next generation
                break;
            case 'o':
                cin >> x >> y;
                // Force cell (x, y) to be alive in this current
                // generation.
                break;
            case 'l':
                cin >> x >> y;
                // Add rule 2 to cell (x, y)
                break;
            case 'a':
                cin >> x >> y;
                // Add rule 3 to cell (x, y)
                break;
            case 't':
                cin >> x >> y >> N;
                // Add rule 4 to cell (x, y) with period N
                break;
            case 'f':
                cin >> x >> y >> N;
                // Add rule 5 to cell (x, y) with desired neighbours N
                break;
            case 'd':
                // Read in letters denoting the default ruleset to
                // apply to every cell in the grid.
                // l -> rule 2 from spec (underpopulation)
                // a -> rule 3 from spec (overpopulation)
                // t -> rule 4 from spec (periodic cell)
                // f -> rule 5 from spec (friendly cell)
                // Any other character = stop reading and set default
                // from rules currently read.

                // All these cells will be dead, so this also effectively
                // resets the game.

                // Example if you see "dal*" then you would set the
                // default for all cells to rule 3 + rule 2. Note that
                // this default is the "normal" game of life.

                // Another Example: "daf7-" would apply rule 3 then
                // rule 5 with N set to 7.
                break;
            case 'p':
                // Print the grid - living cells should be printed as
                // X's, while dead cells should be printed as .'s
                break;
            case 'q':
                // Quit the program.
                return;
        }
    }
}
