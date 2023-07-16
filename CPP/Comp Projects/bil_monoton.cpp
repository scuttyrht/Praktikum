#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cout << "Masukkan 4 angka: ";
    cin >> a >> b >> c >> d;
    
    if (a == b && b == c && c == d) {
        cout << "KONSTAN" << endl;
    }
    else if (a <= b && b <= c && c <= d) {
        cout << "MONOTON MENAIK" << endl;
    }
    else if (a >= b && b >= c && c >= d) {
        cout << "MONOTON MENURUN" << endl;
    }
    else {
        cout << "TIDAK MONOTON" << endl;
    }
}