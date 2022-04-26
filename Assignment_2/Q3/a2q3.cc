#include<iostream>
#include<fstream>
#include<string>
#include <sstream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::istringstream;
int main (int argc, char* argv[]) {
	int i = 1;
	bool foundc = false;
	bool foundd = false;
	int cstart = 0;
	int cend = 0;
	string c1;
	istream *input = &cin;
	ostream *output1 = &cout;
	int nlist[30];
	while(i < argc) {
		string s1{argv[i]};
		if (s1.find("-f") != std::string::npos) {
                     	if (argc == 5) {
				input = new ifstream (argv[3]);
				output1 = new ofstream(argv[4]);
			} else if (argc == 4) {
				input = new ifstream (argv[3]);
			}
			foundd = true;
			string dummy1 ="";
			string dummy2 = "";
			std::istringstream ss(s1);
			getline(ss, dummy1, 'f');
			int z = 0;
			while(getline(ss, dummy2, ',')) {
				nlist[z] = stoi(dummy2);
				z++;
			}
			nlist[z] = stoi(dummy2);
			string s3{argv[2]};
			c1[0] = s3[2];
                }
		if (s1.find("-c") != std::string::npos) {
                        if (argc == 4) {
				input = new ifstream (argv[2]);
				output1 = new ofstream(argv[3]);
			} else if (argc == 3) {
				input = new ifstream (argv[2]);
			}
			foundc = true;
			string dummy1 ="";
                        string dummy2 = "";
                        std::istringstream ss(s1);
			getline(ss, dummy1, 'c');
			getline(ss, dummy2, '-');
			cstart = stoi(dummy2);
			getline(ss, dummy2, '\n');
			cend = stoi(dummy2);
              }
		i++;
	}
	
	string inputline;
	while(getline(*input, inputline)) {
		string output;
		if (foundc) {
			i = 0;
			int q = inputline.length();
			string ctos[1];
			while(i < q) {	
				if ((i >= (cstart- 1)) && (i <= (cend - 1))) {
				       ctos[0] = inputline[i];
				       output += ctos[0];
                                }
				if (i > (cend - 1)) {
                                        break;
                                }
				i++;
			}
			*output1 << output << endl;
		}
		if (foundd){
			std::istringstream s{inputline};
                        std::string s2;
			i = 1;
			char c = c1[0];
			int k = 0;
			while (std::getline(s, s2, c)) {
				bool foundn = false;
				int a = 0;
				int l = sizeof(nlist)/sizeof(a);
				while(a < l) {
					if(nlist[a] == i) {
						foundn = true;
						k++;
					}
					a++;
				}
				if(foundn) {
				       if(k > 1) {	
					output += c1[0];
				       }
					output += s2;
				}
			i++;
			}
			*output1 << output << endl;
		}
	}
	if ( input != &cin ) delete input;
	if ( output1 != &cout ) delete output1;
}
