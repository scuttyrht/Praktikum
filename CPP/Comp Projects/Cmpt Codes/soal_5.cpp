#include <iostream>
#include <string>
using namespace std;

int main() {
    int amt;
    string formt, spc = " ";

    cin >> amt; cin >> formt;
    
    for (int i = 1; i <= amt; i++) {
        if (i == 1) {
            cout << formt[0] << endl;
        } else if (i == 2) {
            cout << formt[0] << formt[2] << endl;
        } else if (i > 2 && i < amt) {
            cout << formt[0];
            for (int j = 0; j < i-2; j++) {
                cout << spc;
            }
            cout << formt[2] << endl;
        } else if (i == amt) {
            for (int j = 1; j < amt; j++) {
                cout << formt[1];
            }
            cout << formt[2] << endl;
        }
    }
}