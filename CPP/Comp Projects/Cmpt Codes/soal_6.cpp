#include <iostream>
#include <string>
using namespace std;

void flip(int x, int y, int M) {
    
}

int main() {
    string cmd = "CONTINUE";
    int N, x, y, M;
    
    do {
        cin >> N;
        if (N < 1 || N > 10) {
            cout << "Masukkan diantara 1 - 10" << endl;
        }
    } while (N < 1 || N > 10);
    int loyak[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            loyak[i][j] = 0;
        }
    }
    
    while (cmd == "CONTINUE") {
        cin >> x >> y >> M;

        for (int i = x; i < (M + x); i++) {
            for (int j = y; j < (M + y); j++) {
                if (loyak[i][j] == 1) loyak[i][j] = 0;
                else loyak[i][j] = 1;
            }   
        }

        if (x == 0 && y == 0 && M == 0) cmd = "STOP";
        if (cmd == "STOP") break; 
    }
    
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << loyak[i][j] << " ";
        }
        cout << endl;
    }
}