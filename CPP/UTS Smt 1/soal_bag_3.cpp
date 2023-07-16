/*
 * @author scuttyrht
 * @date 2022-11-10
 * @version 1.0
 */

#include <iostream>

using namespace std;

int main() 
{
    int baris;

    cin >> baris;

    for (int i = 1; i <= baris; i++) {
        for (int j = 1; j <= i; j++) {
            cout << i << "\t";
        }
        cout << endl;   
    }
}