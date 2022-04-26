#include <iostream>
#include "textdisplay.h"
#include "subject.h"
#include "observer.h"
#include "cell.h"

using namespace std; 

void TextDisplay::notify(Cell &whoNotified) {
    int r = whoNotified.getRow();
    int c = whoNotified.getCol();
    if(theDisplay[r][c] == '.') {
        theDisplay[r][c] = 'X';  
    } else {
        theDisplay[r][c] = '.';
    }
}

TextDisplay::TextDisplay(int n){
    gridSize = n;
    for (int i = 0; i < gridSize; i ++) {
        vector<char> ct;
         for (int k = 0; k < gridSize; k++) {
               ct.emplace_back('.');
          }
          theDisplay.emplace_back(ct);
       }
}


TextDisplay::~TextDisplay() {
for (int i = 0; i < gridSize; ++i) {
        theDisplay[i].erase(theDisplay[i].begin(), theDisplay[i].end());
    }
    gridSize = 0;
}


SubscriptionType TextDisplay::subType() const {
  return SubscriptionType::All;
}

std::string TextDisplay::getName() const {
return " ";
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
     for (int r = 0; r < td.gridSize; r++){	
	    	for (int c = 0; c < td.gridSize; c++){
	    	    out << td.theDisplay[r][c];
	    	}
	    	out << std::endl; 
    	}
    return out;
 }

