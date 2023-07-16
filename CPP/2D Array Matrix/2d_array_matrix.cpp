/*
 * @author scuttyrht
 * @date 2022-12-22
 * @version 2.1
 */

#include <iostream>
#include <cstdlib>

using namespace std;
int main() {
    create_matrix:
        int row, col;
        cout << "Masukkan jumlah row\t: ";
        cin >> row;
        cout << "Masukkan jumlah column\t: ";
        cin >> col;
        int matrix[row][col];

        char auto_gen;
        cout << "Auto-generate nilai? (Y/N) ";
        cin >> auto_gen;

        if (auto_gen == 'Y' || auto_gen == 'y'){
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    matrix[i][j] = rand() % 99 + 1;
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
        goto calculate_matrix;
    

    calculate_matrix:
        while (true)
        {
            int choice;
            cout << "\n[1] Tambahkan tiap row\n[2] Kalikan tiap row\n"
            << "[3] Tambahkan tiap column\n[4] Kalikan tiap column\n"
            << "[5] Tambahkan tiap metode diagonal\n[6] Kalikan tiap metode diagonal\n"
            << "[7] Buat ulang matriks\n[8] Keluar" << endl;
            do {
                cout << "Masukkan Pilihan [1/2/3/4/5/6/7/8]: ";
                cin >> choice;
                if (choice < 0 || choice > 8) {
                    cout << "Pilihan invalid" << endl;
                }
            } while (choice < 0 || choice > 8);
            
            switch (choice) {
            case 1:
                int total_sum_row;
                total_sum_row = 0;
                for (int i = 0; i < row; i++) {
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
                for (int i = 0; i < row; i++) {
                    int pdct[row];
                    pdct[i] = 1;
                    for (int j = 0; j < col; j++)
                    {
                        pdct[i] *= matrix[i][j];
                    }
                    cout << "Product row ke-" << (i + 1) << ": " << pdct[i] << endl;
                    total_pdct_row += pdct[i];
                }
                cout << "Product total: " << total_pdct_row << endl;
                system("PAUSE");
                break;

            case 3:
                int total_sum_col;
                total_sum_col = 0;
                for (int i = 0; i < col; i++) {
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
                total_pdct_col = 1;
                for (int i = 0; i < col; i++) {
                    int pdct[col];
                    pdct[i] = 1;
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
                int sum_tlbr, sum_trbl, sum_bltr, sum_brtl;
                sum_tlbr = 0, sum_trbl = 0, sum_bltr = 0, sum_brtl = 0;

                if (row > col) {
                    cout << "Sum diagonal atas kiri - bawah kanan: ";
                    for (int i = 0, j = 0; i < row; i++, j++) {
                        if (j == col) j = 0;
                        sum_tlbr += matrix[i][j];
                        cout << "[" << (i + 1) << "][" << (j + 1) << "] " << matrix[i][j];
                        if (i == row - 1) cout << " = "; else cout << " + ";
                    } cout << sum_tlbr << endl;
                    cout << "Sum diagonal atas kanan - bawah kiri: ";
                    for (int i = 0, j = col - 1; i < row; i++, j--) {
                        if (j < 0) j = col - 1;
                        sum_trbl += matrix[i][j];
                        cout << "[" << (i + 1) << "][" << (j + 1) << "] " << matrix[i][j];
                        if (i == row - 1) cout << " = "; else cout << " + ";
                    } cout << sum_trbl << endl;
                    cout << "Sum diagonal bawah kiri - atas kanan: ";
                    for (int i = row - 1, j = 0; i >= 0; i--, j++) {
                        if (j == col) j = 0;
                        sum_bltr += matrix[i][j];
                        cout << "[" << (i + 1) << "][" << (j + 1) << "] " << matrix[i][j];
                        if (i == 0) cout << " = "; else cout << " + ";
                    } cout << sum_bltr << endl;
                    cout << "Sum diagonal bawah kanan - atas kiri: ";
                    for (int i = row - 1, j = col - 1; i >= 0; i--, j--) {
                        if (j < 0) j = col - 1;
                        sum_brtl += matrix[i][j];
                        cout << "[" << (i + 1) << "][" << (j + 1) << "] " << matrix[i][j];
                        if (i == 0) cout << " = "; else cout << " + ";
                    } cout << sum_brtl << endl;
                } else if (col > row) {
                    cout << "Sum diagonal atas kiri - bawah kanan: ";
                    for (int i = 0, j = 0; j < col; i++, j++) {
                        if (i == row) i = 0;
                        sum_tlbr += matrix[i][j];
                        cout << "[" << (i + 1) << "][" << (j + 1) << "] " << matrix[i][j];
                        if (j == col - 1) cout << " = "; else cout << " + ";
                    } cout << sum_tlbr << endl;
                    cout << "Sum diagonal atas kanan - bawah kiri: ";
                    for (int i = 0, j = col - 1; j >= 0; i++, j--) {
                        if (i == row) i = 0;
                        sum_trbl += matrix[i][j];
                        cout << "[" << (i + 1) << "][" << (j + 1) << "] " << matrix[i][j];
                        if (j == 0) cout << " = "; else cout << " + ";
                    } cout << sum_trbl << endl;
                    cout << "Sum diagonal bawah kiri - atas kanan: ";
                    for (int i = row - 1, j = 0; j < col; i--, j++) {
                        if (i < 0) i = row - 1;
                        sum_bltr += matrix[i][j];
                        cout << "[" << (i + 1) << "][" << (j + 1) << "] " << matrix[i][j];
                        if (j == col - 1) cout << " = "; else cout << " + ";
                    } cout << sum_bltr << endl;
                    cout << "Sum diagonal bawah kanan - atas kiri: ";
                    for (int i = row - 1, j = col - 1; j >= 0; i--, j--) {
                        if (i < 0) i = row - 1;
                        sum_brtl += matrix[i][j];
                        cout << "[" << (i + 1) << "][" << (j + 1) << "] " << matrix[i][j];
                        if (j == 0) cout << " = "; else cout << " + ";
                    } cout << sum_brtl << endl;
                } else {
                    cout << "Sum diagonal atas kiri - bawah kanan: ";
                    for (int i = 0, j = 0; i < row && j < col; i++, j++) {
                        sum_tlbr += matrix[i][j];
                    }
                    cout << "Sum diagonal atas kanan - bawah kiri: ";
                    for (int i = 0, j = col - 1; i < row && j >= 0; i++, j--) {
                        sum_trbl += matrix[i][j];
                    }
                    cout << "Sum diagonal bawah kiri - atas kanan: ";
                    for (int i = row - 1, j = 0; i >= 0 && j < col; i--, j++) {
                        sum_bltr += matrix[i][j];
                    }
                    cout << "Sum diagonal bawah kanan - atas kiri: ";
                    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
                        sum_brtl += matrix[i][j];
                    }
                }
                cout << "Total sum diagonal: " << (sum_tlbr + sum_trbl + sum_bltr + sum_brtl) << endl;
                system("PAUSE");
                break;

            case 6:
                int pdct_tlbr, pdct_trbl, pdct_brtl, pdct_bltr;
                pdct_tlbr = 1, pdct_trbl = 1, pdct_brtl = 1, pdct_bltr = 1;

                if (row > col) {
                    cout << "Product diagonal atas kiri - bawah kanan: ";
                    for (int i = 0, j = 0; i < row; i++, j++) {
                        if (j == col) j = 0;
                        pdct_tlbr *= matrix[i][j];
                        cout << "[" << (i + 1) << "][" << (j + 1) << "] " << matrix[i][j];
                        if (i == row - 1) cout << " = "; else cout << " * ";
                    } cout << pdct_tlbr << endl;
                    cout << "Product diagonal atas kanan - bawah kiri: ";
                    for (int i = 0, j = col - 1; i < row; i++, j--) {
                        if (j < 0) j = col - 1;
                        pdct_trbl *= matrix[i][j];
                        cout << "[" << (i + 1) << "][" << (j + 1) << "] " << matrix[i][j];
                        if (i == row - 1) cout << " = "; else cout << " * ";
                    } cout << pdct_trbl << endl;
                    cout << "Product diagonal bawah kiri - atas kanan: ";
                    for (int i = row - 1, j = 0; i >= 0; i--, j++) {
                        if (j == col) j = 0;
                        pdct_bltr *= matrix[i][j];
                        cout << "[" << (i + 1) << "][" << (j + 1) << "] " << matrix[i][j];
                        if (i == 0) cout << " = "; else cout << " * ";
                    } cout << pdct_bltr << endl;
                    cout << "Product diagonal bawah kanan - atas kiri: ";
                    for (int i = row - 1, j = col - 1; i >= 0; i--, j--) {
                        if (j < 0) j = col - 1;
                        pdct_brtl *= matrix[i][j];
                        cout << "[" << (i + 1) << "][" << (j + 1) << "] " << matrix[i][j];
                        if (i == 0) cout << " = "; else cout << " * ";
                    } cout << pdct_brtl << endl;
                } else if (col > row) {
                    cout << "Product diagonal atas kiri - bawah kanan: ";
                    for (int i = 0, j = 0; j < col; i++, j++) {
                        if (i == row) i = 0;
                        pdct_tlbr *= matrix[i][j];
                        cout << "[" << (i + 1) << "][" << (j + 1) << "] " << matrix[i][j];
                        if (j == col - 1) cout << " = "; else cout << " * ";
                    } cout << pdct_tlbr << endl;
                    cout << "Product diagonal atas kanan - bawah kiri: ";
                    for (int i = 0, j = col - 1; j >= 0; i++, j--) {
                        if (i == row) i = 0;
                        pdct_trbl *= matrix[i][j];
                        cout << "[" << (i + 1) << "][" << (j + 1) << "] " << matrix[i][j];
                        if (j == 0) cout << " = "; else cout << " * ";
                    } cout << pdct_trbl << endl;
                    cout << "Product diagonal bawah kiri - atas kanan: ";
                    for (int i = row - 1, j = 0; j < col; i--, j++) {
                        if (i < 0) i = row - 1;
                        pdct_bltr *= matrix[i][j];
                        cout << "[" << (i + 1) << "][" << (j + 1) << "] " << matrix[i][j];
                        if (j == col - 1) cout << " = "; else cout << " * ";
                    } cout << pdct_bltr << endl;
                    cout << "Product diagonal bawah kanan - atas kiri: ";
                    for (int i = row - 1, j = col - 1; j >= 0; i--, j--) {
                        if (i < 0) i = row - 1;
                        pdct_brtl *= matrix[i][j];
                        cout << "[" << (i + 1) << "][" << (j + 1) << "] " << matrix[i][j];
                        if (j == 0) cout << " = "; else cout << " * ";
                    } cout << pdct_brtl << endl;
                } else {
                    cout << "Product diagonal atas kiri - bawah kanan: ";
                    for (int i = 0, j = 0; i < row && j < col; i++, j++) {
                        pdct_tlbr *= matrix[i][j];
                    }
                    cout << "Product diagonal atas kanan - bawah kiri: ";
                    for (int i = 0, j = col - 1; i < row && j >= 0; i++, j--) {
                        pdct_trbl *= matrix[i][j];
                    }
                    cout << "Product diagonal bawah kiri - atas kanan: ";
                    for (int i = row - 1, j = 0; i >= 0 && j < col; i--, j++) {
                        pdct_bltr *= matrix[i][j];
                    }
                    cout << "Product diagonal bawah kanan - atas kiri: ";
                    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
                        pdct_brtl *= matrix[i][j];
                    }
                }
                cout << "Total product diagonal: " << (pdct_tlbr + pdct_trbl + pdct_bltr + pdct_brtl) << endl;
                system("PAUSE");
                break;

            case 7:
                goto create_matrix;

            case 8:
                exit(0);
                break;
            }
        }
}