#include <iostream>
using namespace std; 

int main () {
int n; 
cin >> n; 
bool range = false; 
if ( n >= 1 and n <= 3) range = true;

if (range) cout<< range << "is in range " << endl;
else {
cout << range << endl;
cout << "is not in range " << endl;
}

}
