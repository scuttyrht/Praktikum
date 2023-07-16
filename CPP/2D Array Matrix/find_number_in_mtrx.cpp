#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;
int main() {
    int row, col, numToFind;
    string indexHasNum = "";
    cout << "Masukkan jumlah row\t: ";
    cin >> row;
    cout << "Masukkan jumlah column\t: ";
    cin >> col;
    int matrix[row][col], numInMatrix[row*col];

    char auto_gen;
    cout << "Auto-generate nilai? (Y/N) ";
    cin >> auto_gen;

    if (auto_gen == 'Y' || auto_gen == 'y'){
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                matrix[i][j] = rand() % 9 + 1;
            }
        }
    } else {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << "Masukkan untuk [" << i + 1 << "][" << j + 1 << "]: ";
                cin >> matrix[i][j];
            }
        }
    }
    
    for (int i = 0; i < row; i++) {
        if (row == 1) {
            cout << "[\t";
        } else if (i == 0) {
            cout << "⸢\t";
        } else if (i == (row - 1)) {
            cout << "⸤\t";
        } else {
            cout << "|\t";
        }
        
        for (int j = 0; j < col; j++) {
            cout << matrix[i][j] << "\t";
        }

        if (row == 1) {
            cout << "]" << endl;
        } else if (i == 0) {
            cout << "⸣" << endl;
        } else if (i == (row - 1)) {
            cout << "⸥" << endl;
        } else {
            cout << "|" << endl;
        }
    }
    cout << "Cari angka dalam matrix: ";
    cin >> numToFind;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == numToFind) {
                indexHasNum += "("; indexHasNum += to_string(i + 1); indexHasNum += ", "; 
                indexHasNum += to_string(j + 1); indexHasNum += "), ";
            }
        }
    }
    cout << numToFind << " ditemui dalam [" << indexHasNum << "\b\b]";
}