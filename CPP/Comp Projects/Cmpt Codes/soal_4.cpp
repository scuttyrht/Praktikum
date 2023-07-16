#include <iostream>
using namespace std;

int main() {
    int a, b, c;

    cin >> a >> b >> c;
    
    if (c < a && c < b) {
        cout << "Kiri" << endl;
    } else if (c == a || c == b) {
        cout << "Tepi" << endl;
    } else if (c > a && c > b) {
        cout << "Kanan" << endl;
    } else {
        cout << "Tengah" << endl;
    }

    cout << "test";
}