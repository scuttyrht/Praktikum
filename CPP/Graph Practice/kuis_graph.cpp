#include <iostream>
using namespace std;

struct Simpul {
    int info;
    Simpul *left, *right;
};

Simpul *P, *first, *last, *Q, *R;
Simpul *points[6]; // Mengubah ukuran array points menjadi 6

int main(){
    // Pendefinisian adjacency matrix bobot ordo 6x6
    int A[6][6] = { {0, 5, 0, 2, 0, 0},
                    {6, 0, 3, 0, 0, 0},
                    {0, 0, 0, 0, 9, 0},
                    {0, 0, 12, 0, 7, 0},
                    {0, 14, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0} // Baris dan kolom baru dengan bobot 0
    };

    int nosimpul[6] = {1, 2, 3, 4, 5, 6}; // Mengubah ukuran array nosimpul menjadi 6
    int i, j;

    // Simpul 1
    i = 0; j = 0;
    P = new Simpul;
    P->info = nosimpul[0];
    first = P;
    last = P;
    P->left = NULL;
    P->right = NULL;
    points[0] = P;

    cout << "Simpul ke- " << P->info;
    cout << " alamat: " << points[0] << endl;

    // Simpul vertex berikutnya
    for (i=1; i <= 5; i++){ // Mengubah batas perulangan menjadi 5
        P = new Simpul;
        P->info = nosimpul[i];
        last->left = P;
        last = last->left;
        P->left = NULL;
        P->right = NULL;
        points[i] = P;

        cout << "Simpul ke- " << P->info;
        cout << " alamat: " << points[i] << endl;
    }

    // Simpul edge untuk semua vertex
    cout << endl;
    Q = first;
    for (i = 0; i <= 5; i++){
        R = Q;
        cout  << "vertex " << Q->info << ":\n";
        for (j = 0; j <= 5; j++){
            if (A[i][j] != 0){
                P = new Simpul;
                P->info = A[i][j];
                R->right = P;
                P->left = points[j];
                cout << "Berhubungan dengan " << P->left->info;
                cout << " dengan bobot " << P->info << ". ";
                P->right = NULL;
                R = P;
           } else {
               "Tidak memiliki bobot";
           } 
        }
        cout << endl;
        Q = Q->left;
    }
};
