/*
 * @author scuttyrht
 * @date 2022-12-22
 * @version 2.0
 */

#include <iostream>

using namespace std;
int main() {
    create_matrix:
        int row, col;
        cout << "Masukkan jumlah row\t: ";
        cin >> row;
        cout << "Masukkan jumlah column\t: ";
        cin >> col;
        int matrix[row][col];

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << "Masukkan untuk [" << i + 1 << "][" << j + 1 << "]: ";
                cin >> matrix[i][j];
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
        goto calculate_matrix;
    

    calculate_matrix:
        while (true)
        {
            int choice;
            cout << "\n[1] Tambahkan tiap row\n[2] Kalikan tiap row\n"
            << "[3] Tambahkan tiap column\n[4] Kalikan tiap column\n"
            << "[5] Buat ulang matriks\n[6] Keluar" << endl;
            do {
                cout << "Masukkan Pilihan [1/2/3/4/5/6]: ";
                cin >> choice;
                if (choice < 0 || choice > 6) {
                    cout << "Pilihan invalid" << endl;
                }
            } while (choice < 0 || choice > 6);
            
            switch (choice) {
            case 1:
                int total_sum_row;
                total_sum_row = 0;
                for (int i = 0; i < row; i++)
                {
                    int sum[row];
                    sum[i] = 0;
                    for (int j = 0; j < col; j++)
                    {
                        sum[i] += matrix[i][j];
                    }
                    cout << "Sum row ke-" << (i + 1) << ": " << sum[i] << endl;
                    total_sum_row += sum[i];
                }
                cout << "Sum total: " << total_sum_row << endl;
                system("PAUSE");
                break;

            case 2:
                int total_pdct_row;
                total_pdct_row = 0;
                for (int i = 0; i < row; i++)
                {
                    int product[row];
                    product[i] = 0;
                    for (int j = 0; j < col; j++)
                    {
                        product[i] *= matrix[i][j];
                    }
                    cout << "Product row ke-" << (i + 1) << ": " << product[i] << endl;
                    total_pdct_row += product[i];
                }
                cout << "Product total: " << total_pdct_row << endl;
                system("PAUSE");
                break;

            case 3:
                int total_sum_col;
                total_sum_col = 0;
                for (int i = 0; i < col; i++)
                {
                    int sum[col];
                    sum[i] = 0;
                    for (int j = 0; j < row; j++)
                    {
                        sum[i] += matrix[j][i];
                    }
                    cout << "Sum col ke-" << (i + 1) << ": " << sum[i] << endl;
                    total_sum_col += sum[i];
                }
                cout << "Sum total: " << total_sum_col << endl;
                system("PAUSE");
                break;

            case 4:
                int total_pdct_col;
                total_pdct_col = 0;
                for (int i = 0; i < col; i++)
                {
                    int pdct[col];
                    pdct[i] = 0;
                    for (int j = 0; j < row; j++)
                    {
                        pdct[i] *= matrix[j][i];
                    }
                    cout << "Sum col ke-" << (i + 1) << ": " << pdct[i] << endl;
                    total_pdct_col += pdct[i];
                }
                cout << "Sum total: " << total_pdct_col << endl;
                system("PAUSE");
                break;

            case 5:
                goto create_matrix;

            case 6:
                exit(0);
                break;
            }
        }
    
}