#include<iostream>
using namespace std;

struct Anggota
{
    int id;
    string nama;
    Anggota *next;
};


int main(int argc, char const *argv[])
{
    Anggota *node[3], *cur;
    for (int i = 0; i < 3; i++)
    {
        node[i] = new Anggota();
    }
    node[0]->id = 1234;
    node[0]->nama = "Iklima";
    node[0]->next = node[1];
    node[1]->id = 1235;
    node[1]->nama = "Ermis";
    node[1]->next = node[2];
    node[2]->id = 1236;
    node[2]->nama = "Ismail";
    node[2]->next = NULL;

    cur = node[0];
    while (cur != NULL)
    {
        cout << "ID Anggota\t: " << cur->id << endl;
        cout << "Nama\t\t: " << cur->nama << endl << endl;
        cur = cur->next;
    }
    
    return 0;
}
