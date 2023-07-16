#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int matriks[2][4][4] 
    = {{{3, 4, 5, 5}, {5, 6, 7, 9}, {1, 7, 11, 10}, {2, 8, 9, 4}},
      {{1, 2, 3, 4}, {8, 7, 6, 5}, {9, 10, 11, 2}, {6, 5, 4, 3}}};
    int hasil[2][4][4];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            hasil[0][i][j] = matriks[0][i][j] + matriks[1][i][j];
        }
    }
    cout << "Hasil pertambahan kedua matriks:" << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << hasil[0][i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            hasil[1][i][j] = 0;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                hasil[1][i][j] += matriks[0][i][k] * matriks[1][k][j];
            }
        }
    }
    cout << "Hasil perkalian kedua matriks:" << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << hasil[1][i][j] << "\t";
        }
        cout << endl;
    }
    
    system("PAUSE");
    return 0;
}
