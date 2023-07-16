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

struct pegawai
{
    string nama;
    int jam_kerja;
    int gaji_harian;
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

int getGajiHarian(int jam_kerja) {
    int gaji_perjam = 6000, gaji_harian;
    if (jam_kerja > 40) {
        gaji_harian = 40 * gaji_perjam + (jam_kerja - 40) * 3 * gaji_perjam;
        return gaji_harian;
    } else {
        gaji_harian = jam_kerja * gaji_perjam;
        return gaji_harian;
    }
}

int main(int argc, char const *argv[]) {
    int pilihan;
    bool cont = true;

    do {
        cout << "[1] Hitung nilai akhir mahasiswa"
        << "\n[2] Hitung gaji pegawai perminggu"
        << "\n[3] Exit\n[1/2/3] Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                int jmlh_data;
                cout << "Masukkan jumlah data mahasiswa: "; cin >> jmlh_data;
                mahasiswa mhsw[jmlh_data];
                for (int i = 0; i < jmlh_data; i++) {
                    cout << "Masukkan nama mahasiswa ke-" << i+1 << "\t: "; cin >> mhsw[i].nama;
                    cout << "Masukkan total nilai tugas\t: "; cin >> mhsw[i].tugas;
                    cout << "Masukkan total nilai kuis\t: "; cin >> mhsw[i].kuis;
                    cout << "Masukkan nilai UTS\t\t: "; cin >> mhsw[i].mid;
                    cout << "Masukkan nilai UAS\t\t: "; cin >> mhsw[i].uas;
                }
                for (int i = 0; i < jmlh_data; i++) {
                    mhsw[i].nilai_akhir = getNilaiAkhir(mhsw[i].tugas, mhsw[i].kuis, mhsw[i].mid, mhsw[i].uas);
                    cout << "Nilai total " << mhsw[i].nama << " adalah: " << mhsw[i].nilai_akhir 
                    << " dengan huruf mutlak " << getNilaiMutlak(mhsw[i].nilai_akhir) << endl;
                }
                break;
            }
            case 2: {
                int jmlh_data;
                cout << "Masukkan jumlah data pegawai: "; cin >> jmlh_data;
                pegawai peg[jmlh_data];

                for (int i = 0; i < jmlh_data; i++) {
                    cout << "Masukkan nama pegawai ke-"<< i+1 <<"\t: "; cin >> peg[i].nama;
                    cout << "Masukkan jumlah jam kerja\t: "; cin >> peg[i].jam_kerja;
                }
                for (int i = 0; i < jmlh_data; i++) {
                    peg[i].gaji_harian = getGajiHarian(peg[i].jam_kerja);
                    cout << "Gaji harian " << peg[i].nama << ": " << peg[i].gaji_harian << endl;
                }
                break;
            }
            case 3: {
                cont = false;
                break;
            }
            default: {
                "Pilihan tidak tersedia\n";
                break;
            }
        }
    } while (cont == true);

    return 0;
}
