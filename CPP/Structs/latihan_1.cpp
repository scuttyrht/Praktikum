#include <iostream>
using namespace std;

struct mahasiswa
{
    string nama;
    int tugas;
    int kuis;
    int mid;
    int uas;
    double nilai_akhir;
};

double getNilaiAkhir(int tugas, int kuis, int mid, int uas) {
    double nilai_akhir = ((double)tugas*30/100) + ((double)kuis/10) + ((double)mid*30/100) + ((double)uas*30/100);
    return nilai_akhir;
}

string getNilaiMutlak(double nilai_akhir) {
    if (nilai_akhir > 85) return "A";
    else if (nilai_akhir > 70) return "B";
    else if (nilai_akhir > 55) return "C";
    else if (nilai_akhir > 40) return "D";
    else return "E";
}

int main(int argc, char const *argv[]) {
    mahasiswa mhsw;
    cout << "Masukkan nama mahasiswa\t: "; cin >> mhsw.nama;
    cout << "Masukkan total nilai tugas\t: "; cin >> mhsw.tugas;
    cout << "Masukkan total nilai kuis\t: "; cin >> mhsw.kuis;
    cout << "Masukkan nilai UTS\t\t: "; cin >> mhsw.mid;
    cout << "Masukkan nilai UAS\t\t: "; cin >> mhsw.uas;
    mhsw.nilai_akhir = getNilaiAkhir(mhsw.tugas, mhsw.kuis, mhsw.mid, mhsw.uas);
    cout << "Nilai total " << mhsw.nama << " adalah: " << mhsw.nilai_akhir 
    << " dengan huruf mutlak " << getNilaiMutlak(mhsw.nilai_akhir) << endl;
    system("PAUSE");
    return 0;
}