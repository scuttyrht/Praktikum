/*
 * @author scuttyrht
 * @date 2023-1-11
 * @version 1.0
 */

#include <iostream>

using namespace std;

int sum(int n) {
    if (n > 0) {
        return n + sum(n - 1);
    } else {
        return 0;
    }
}

int fact(int n) {
    if (n > 1) {
        return n + fact(n - 1);
    } else {
        return 1;
    }
}

int main() {
    cout << "FUNGSI REKURSIF" << endl;

    while (true){
        int ch;

        do {
            cout << "[1] Sum\n[2] Faktorial\n[3] Keluar\n Masukkan Pilihan: [1/2/3] ";
            cin >> ch;

            if (ch != 1 && ch != 2 && ch != 3 && cin.fail()) {
                cout << "Pilihan tidak tersedia" << endl;
            }
        } while (ch != 1 && ch != 2 && ch != 3 && cin.fail());

        if (ch == 3) {
            break;
        }

        switch (ch) {
            case 1:
                int sumnum;
                do {
                    cout << "Masukkan nilai untuk rekursif sum: ";
                    cin >> sumnum;

                    if (sumnum <= 0) {
                        cout << "Pastikan angka lebih dari 0" << endl;
                    }
                } while (sumnum <= 0);
                cout << "Hasil hitungan rekursif sum: " << sum(sumnum) << endl;
                system("PAUSE");
                break;
            case 2:
                int factnum;
                do {
                    cout << "Masukkan nilai untuk rekursif faktorial: ";
                    cin >> factnum;

                    if (factnum <= 0) {
                        cout << "Pastikan angka lebih dari 0 " << endl;
                    }
                } while (factnum <= 0);
                cout << "Hasil hitungan rekursif faktorial: " << fact(factnum) << endl;
                system("PAUSE");
                break;
        }
    }
    system("PAUSE");
}