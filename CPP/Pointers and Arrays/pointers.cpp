#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int x = 2, *px;
    px = &x;
    cout << "Nilai yang disimpan 'x' = " << x << endl;
    cout << "Alamat '*px' = " << *px << endl;
    cout << "==============================" << endl;

    char A[12] = "A", *pA[12];
    pA[12] = &A[12];
    cout << "Nilai yang disimpan array 'A' = " << A << endl;
    cout << "Alamat '*pA' = " << *pA << endl;
    cout << "====================================";
    return 0;
}
