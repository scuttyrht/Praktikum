/*
 * @author scuttyrht
 * @date 2023-1-18
 * @version 1.0
 */

#include <iostream>
#include <cstdlib>

using namespace std;
int main() {
    int m, n, sum;
    cout << "Masukkan jumlah row matriks 1\t: ";
    cin >> m;
    cout << "Jumlah col matriks 2\t\t: " << m << endl;
    cout << "Masukkan jumlah col matriks 1\t: ";
    cin >> n;
    cout << "Jumlah row matriks 2\t\t: " << n << endl;
    int matrix1[m][n], matrix2[n][m], matrix3[m][m];

    cout << "MATRIKS 1" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Masukkan untuk [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix1[i][j];
        }
    }
    cout << endl;
    cout << "MATRIKS 2" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Masukkan untuk [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix2[i][j];
        }
    }
    
    for (int i = 0; i < m; i++) {
        if (m == 1) {
            cout << "[\t";
        } else if (i == 0) {
            cout << "⸢\t";
        } else if (i == (m - 1)) {
            cout << "⸤\t";
        } else {
            cout << "|\t";
        }
        
        for (int j = 0; j < n; j++) {
            cout << matrix1[i][j] << "\t";
        }

        if (m == 1) {
            cout << "]" << endl;
        } else if (i == 0) {
            cout << "⸣" << endl;
        } else if (i == (m - 1)) {
            cout << "⸥" << endl;
        } else {
            cout << "|" << endl;
        }
    }
    cout << "     X" << endl;
    for (int i = 0; i < n; i++) {
        if (n == 1) {
            cout << "[\t";
        } else if (i == 0) {
            cout << "⸢\t";
        } else if (i == (n - 1)) {
            cout << "⸤\t";
        } else {
            cout << "|\t";
        }
        
        for (int j = 0; j < m; j++) {
            cout << matrix2[i][j] << "\t";
        }

        if (n == 1) {
            cout << "]" << endl;
        } else if (i == 0) {
            cout << "⸣" << endl;
        } else if (i == (n - 1)) {
            cout << "⸥" << endl;
        } else {
            cout << "|" << endl;
        }
    }
    cout << "     =" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                sum += matrix1[i][k]*matrix2[k][j];
            }
            matrix3[i][j] = sum;
            sum = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        if (m == 1) {
            cout << "[\t";
        } else if (i == 0) {
            cout << "⸢\t";
        } else if (i == (m - 1)) {
            cout << "⸤\t";
        } else {
            cout << "|\t";
        }
        
        for (int j = 0; j < m; j++) {
            cout << matrix3[i][j] << "\t";
        }

        if (m == 1) {
            cout << "]" << endl;
        } else if (i == 0) {
            cout << "⸣" << endl;
        } else if (i == (m - 1)) {
            cout << "⸥" << endl;
        } else {
            cout << "|" << endl;
        }
    }
}