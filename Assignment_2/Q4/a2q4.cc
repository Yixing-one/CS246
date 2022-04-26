#include <iostream>
#include <sstream>
using namespace std;
const int MAX_INT_SETS = 5;

struct IntSet {
  int *data;
  int size;
  int capacity;
};

void init( IntSet & i ) {
	i.data = nullptr;
	i.size = 0;
	i.capacity = 0;
}
// Initialize to be "empty" with following field values: {nullptr,0,0}

void destroy( IntSet & i ){
	if (i.data != nullptr) {
		delete [] i.data;
	}
}
// Clean up the IntSet and free dynamically allocated memory.
void add( IntSet & i, int e ); 
IntSet operator| ( const IntSet & i1, const IntSet & i2 ){
	IntSet i3 {};
	init(i3);
	int i = 0;
	int h = 0;
	while(h < i1.size) {
		 add(i3, i1.data[h]);
		 h++;
	}
	while(i < i2.size) {
		int n = i2.data[i];
		int q = 0;
		bool notfound = true;
		while(q < i1.size) {
			if(n == i1.data[q]) {
				notfound = false;
			}
			q++;
		}
		if(notfound) {
			add(i3, n);
		}
		i++;
	}
	return i3;
}
	// Set union.
IntSet operator& ( const IntSet & i1, const IntSet & i2 ) {
      	IntSet i3 {};
	init(i3);
	int i = 0;
	while(i < i2.size) {
		int n = i2.data[i];
		int q = 0;
		bool found = true;
		while(q < i1.size) {
			if(n == i1.data[q]) {
				found = false;
			}
			q++;
		}
		if(found) {
			add(i3, n);
		}
		i++;
	}
	return i3;
}	
// Set intersection.
bool isSubset( const IntSet & i1, const IntSet & i2 );
bool   operator==( const IntSet & i1, const IntSet & i2 ) {
	bool ifEqual = (isSubset(i1, i2) && isSubset(i2,i1));
	return  ifEqual;
}
// Set equality.

bool isSubset( const IntSet & i1, const IntSet & i2 ){
	bool ifSubset = true;
	int i = 0;
        while(i < i2.size) {
		int n = i2.data[i];
		int q = 0;
		bool found = false;
		while(q < i1.size) {
			if(n == i1.data[q]) {
				found = true;
			}
			q++;
		}
		if(!found) {
			ifSubset = false;
			break;
		}
		i++;
	}
 	return ifSubset;
}	
	// True if i2 is a subset of i1.
bool contains( const IntSet & i, int e ) {
	bool ifContain = false;
        int q = 0;
	while(q < i.size) {
		if(e == i.data[q]) {
		 ifContain = true;
		}
		q++;
	}

       return ifContain;
}	// True if set i contains element e.

void add( IntSet & i, int e ) {
	if (i.size == 0) {
		int *ptr;
		ptr = (int*)malloc( sizeof(int));
		i.data = ptr;
		i.capacity = 1;
	}
	if(! contains (i, e)) {
		int k = i.size;
		 i.size += 1;
		 if(i.size > i.capacity) {
			 i.capacity += 1;
			i.data = (int*)realloc (i.data, i.capacity * sizeof(int));
		 }	
		i.data[k] = e;
	}
}	// Add element e to the set i.

void remove( IntSet & i, int e ) {
	int m = 0;
        while(m < i.size) {
                if(i.data[m]  == e) {
                        int n = m;
			while ((n+1) < i.size) {
				int j = n + 1;
				i.data[n] = i.data[j];
				n++;
			}
			i.size -= 1;
                }
                m++;
        }
}
	// Remove element e from the set i.

// Output operator for IntSet.
std::ostream& operator<<( std::ostream & out, const IntSet & is ) {
	int i = 0;
	if(is.size == 0) {
		out << '('<<')';
	}
	if(is.size != 0) {
		IntSet i3 {};
		out << '(';
		 init(i3);
		int t = 0;
		int j = 0;
		while (j < is.size) {
			add(i3, is.data[j]);
			j++;
			}
		int x = 0;
		while(x <= i3.size - 1) {
			int y = 0;
			while(y <= i3.size - 2) {
				if(i3.data[y] > i3.data[y+1]) {
					t = i3.data[y];
					i3.data[y] = i3.data[y + 1];
					i3.data[y + 1] = t;
				}
				y++;
			}
			x++;
		}
		i = 0;
		while(i < i3.size) {
			out << i3.data[i];
			if(i != i3.size - 1) {
				out << ',';
			}
			i++;
		}

	out << ')';
        destroy(i3);
	}
	return out;
}


// Input operator for IntSet. Continuously read int values from in and add to the passed IntSet.
// Function stops when input contains a non-int value. Discards the first non-int character.
std::istream& operator>>( std::istream & in, IntSet & is ){
	int n = 0;
	while (in >> n) {
	add(is, n);
	}
	in.clear();
	return in;
}

// Test harness for IntSet functions. You may assume that all commands entered are valid.
// Valid commands: n <ind>,  p <ind>, & <ind1> <ind2>,
//                 | <ind1> <ind2>, = <ind1> <ind2>,
//                 s <ind1> <ind2>, c <ind1> <elem>,
//                 a <ind1> <elem>, r <ind1> <elem>,
//                 q/EOF
// Silently ignores invalid commands. Doesn't check that 0 <= index < MAX_INT_SETS.
// Do not test invalid commands!

int main() { 
  bool done = false;
  IntSet sets[MAX_INT_SETS], tmpSet;
  for ( int i = 0; i < MAX_INT_SETS; i++ ) init( sets[i] );
  init( tmpSet );

  while ( ! done ) {
    char c;
    int lhs, rhs;
    cerr << "command?" << endl;
    cin >> c; // Reads command.

    if (cin.eof()) break;
 
    switch(c) {
      case 'n':
        // Create new IntSet at index lhs after destroying the old.
        // Read in integers to add to it until hitting non int using operator>>.
        cin >> lhs;
        destroy( sets[lhs] );
        init( sets[lhs] );
        cerr << "enter integer values for sets[" << lhs << "], terminated by non-int: " << endl;
        cin >> sets[lhs];
        break;

      case 'p':
        // Print IntSet at lhs.
        cin >> lhs;
        cout << sets[lhs] << endl;
        break;

      case '&':
        // Print intersection of lhs and rhs.
        cin >> lhs >> rhs; // reads in two indices
        destroy( tmpSet );
        init( tmpSet );
        tmpSet = (sets[lhs] & sets[rhs]);
        cout << tmpSet << endl;
        break;

      case '|':
        // Print union of lhs and rhs.
        cin >> lhs >> rhs;
        destroy( tmpSet );
        init( tmpSet );
        tmpSet = (sets[lhs] | sets[rhs]);
        cout << tmpSet << endl;
        break;

      case '=':
        // Print true if lhs == rhs, false otherwise.
        cin >> lhs >> rhs;
        cout << boolalpha << (sets[lhs] == sets[rhs]) << endl;
        break;

      case 's':
        // Print true if rhs is subset of lhs, false otherwise.
        cin >> lhs >> rhs;
        cout << boolalpha << isSubset( sets[lhs], sets[rhs] ) << endl;
        break;

      case 'c':
        // Print true if lhs contains element rhs, false otherwise.
        cin >> lhs >> rhs;
        cout << boolalpha << contains( sets[lhs], rhs ) << endl;
        break;

      case 'a':
        // Add elem rhs to set lhs
        cin >> lhs >> rhs;
        add( sets[lhs], rhs );
        break;

      case 'r':
        // Remove elem rhs from set lhs
        cin >> lhs >> rhs;
        remove( sets[lhs], rhs );
        break;
        
      case 'q':
        // Quit
        done = true;
        break;

    } // switch
  } // while

  for ( int i = 0; i < MAX_INT_SETS; i++ ) destroy( sets[i] );
  destroy( tmpSet );
} // main
