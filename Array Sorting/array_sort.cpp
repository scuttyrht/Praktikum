/*
 * @author scuttyrht
 * @date 2022-12-08
 * @version 1.0
 */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main() {
    char cont;
    do {
        int i, j, n, temp, sort_type;
        cout << "Masukkan jumlah angka: ";
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cout << "Masukkan untuk angka " << i+1 << ": ";
            cin >> arr[i];
        }
        cout << "Pilih metode sorting:\n[1] Ascending\n[2] Descending\n[1 / 2]: ";
        do {
            cin >> sort_type;
            if (sort_type != 1 && sort_type != 2) {
                cout << "Pilihan invalid\n[1 / 2]: ";
            }
        } while (sort_type != 1 && sort_type != 2);
        cout << "List input: [";
        for (i = 0; i < n; i++) {
            if ((i + 1) == n) {
                cout << arr[i];
            } else {
                cout << arr[i] << ", ";
            }
        }
        cout << "]" << endl;
        switch (sort_type) {
        case 1:
            for(i = 0; i < n; i++) {
                for(j = i + 1; j < n; j++){
                    if(arr[j] < arr[i]) {
                        temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            break;
        
        case 2:
            for(i = 0; i < n; i++) {
                for(j = i + 1; j < n; j++){
                    if(arr[j] > arr[i]) {
                        temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            break;
        }
        cout << "List sorting: [";
        for (i = 0; i < n; i++) {
            if ((i + 1) == n) {
                cout << arr[i];
            } else {
                cout << arr[i] << ", ";
            }
        }
        cout << "]\n" << "Coba lagi? (Y/N) ";
        cin >> cont;
    } while (cont == 'y' || cont == 'Y');
}