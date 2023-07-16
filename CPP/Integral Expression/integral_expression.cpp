#include <iostream>
using namespace std;
int main() {
    int ch;
    cout << "Choice: ";
    cin >> ch;
    switch (ch) {
    case 1:
        int x, y, z;
        cout << "Enter for values `x` and `y`: ";
        cin >> x >> y ;
        z = x + y;
        cout << "The value for `z` (`x` + `y`) is: " << z;
        break;

    case 2:
        
        break;
    
    default:
        cout << "Bruh";
        break;
    }
}