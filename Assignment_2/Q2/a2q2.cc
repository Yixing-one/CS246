#include<iostream>
#include<string>
#include <iomanip>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main (int argc, char* argv[]) {
	string id;
	string exipireMonth;
	string  exipireDay;
	string  tranNum;
	string  dataDay;
	string dataMonth;
	string dateYear;
	string dateTime;
	string  amount;
	string name;

	while (!cin.fail()) {
	getline(cin, name);
	if(cin.fail()) {
		break;
	}
	getline(cin, id);
	 if(cin.fail()) {
                break;
        }
	cin >> exipireMonth;
	cin >> exipireDay;
	cin >> tranNum;
	cin >> dataDay;
	cin >> dataMonth;
	cin >> dateYear;
	cin >> dateTime;
	cin >> amount;
	
	const int n = id.length();
	int idN[n];
	string validity = "valid";
	int h = 0;
	while (h < n) {
		idN[h] = id[h] - '0';
		h++;
	}

	if (idN[0] != 4) {
		validity = "invalid";
	} else if (n != 13 && n != 16) {
		validity = "invalid";
	} else {
	int idN2[n];
	int h = 0;
	while (h < n) {
		idN2[h] = idN[h];
		h++;
	}
	int i = n - 2;
       	while (i >= 0) {
		int n2 = 0;
		n2 = (idN[i] * 2) % 10;
		if(idN[i] > 4) {
			n2 += 1;
		}
		idN2[i] = n2;
		i -= 2;
	}
	i = n - 1;
	int sum = 0;
	while (i >= 0) {
		sum += idN2[i];
		i--;
	}
	sum = sum % 10;
	if (sum != 0) {
		validity = "invalid";
	}
	}
	cout << setfill('0') << setw(5) << tranNum; 
	cout << " " ;
	cout << setfill('0') << setw(2)  << dataDay; 
	cout << "/";
	cout << setfill('0') << setw(2) << dataMonth;
	cout << "/";
        cout << setfill('0') << setw(2)	<< dateYear;
	cout << " ";
	if(dateTime.length() < 4) {
		cout << "0";
		cout << dateTime[0] << dateTime[1] << dateTime[2];
	} else {
		 cout << dateTime[0] << dateTime[1];
		cout << ":";
	       cout << dateTime[2] << dateTime[3];
	}
	cout << " $";
	cout.precision (5);
	std::cout.precision(2);
	std::cout << std::fixed;
	cout << amount;
	cout << " (";
	cout << id;
	cout << ", ";
	cout << name;
	cout << ", ";
	cout <<  setfill('0') << setw(2) << exipireMonth;
	cout <<  "/";
	cout << setfill('0') << setw(2) << exipireDay;
	cout << ") ";
	cout <<  validity << endl;
	getline(cin,name);
			
	}
}

	










