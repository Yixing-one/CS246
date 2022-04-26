#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <utility>
#include <stdexcept>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
  vector<char> vc;
  vector<int> vi; 
  int x = 0;
  int start = 0;
  int starti = 0;
  
   while (true) {
        char c;
        int k;
        
        cin >> c;
        if(cin.eof()) {
            break;
        }
        
        if(c == 's') {
            cin >> k;
            x = k;
            starti = start;
        } else if((c == '+') || (c == '-') || (c == '*') || (c == '/')) {
            vc.emplace_back(c);
            cin >> k;
            vi.emplace_back(k);
            start++;
        } else if(c == 'n') {
            for(int i = starti; i < start; i++){
                if(vc[i] == '+') {
                    x += vi[i];
                } else if (vc[i] == '-') {
                    x -= vi[i];
                } else if (vc[i] == '*') {
                    x *= vi[i];
                } else if (vc[i] == '/') {
                    x /= vi[i];
                }
            }
            cout << x << endl;
        }
   }
}


