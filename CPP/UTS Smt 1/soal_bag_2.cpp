/*
 * @author scuttyrht
 * @date 2022-11-10
 * @version 1.0
 */

#include <iostream>

using namespace std;

int main() {
    int baris;

    cin >> baris;

    for (int i = 1; i <= baris; i++) {
        for (int j = baris - i; j > 0; j--) {
            cout<<"\t";
        }
        for (int j = 1 ; j <= i; j++) {
            if (i % 2 == 0) {
                cout << "#\t";
            } else {
                cout << "*\t";
            }
        }
        cout << endl;
    }
}