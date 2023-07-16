#include <iostream>
using namespace std;

struct Anggota
{
    int id;
    string nama;
    Anggota *next;
};

Anggota *head, *tail, *cur, *newNode, *del;

void buatSingleLL(int id, string nama) {
    head = new Anggota();
    head->id = id;
    head->nama = nama;
    tail = head;
}

void tampilkanSingleLL() {
    cur = head;
    while (cur != NULL)
    {
        cout << "Nomor ID: " << cur->id << endl;
        cout << "Nama\t: " << cur->nama << endl << endl;
        cur = cur->next;
    }
}

void tambahNextLL(int id, string nama)  {
    newNode = new Anggota();
    newNode->id = id;
    newNode->nama = nama;
    newNode->next = head;
    head = newNode;
}

void tambahBackLL(int id, string nama) {
    newNode = new Anggota();
    newNode->id = id;
    newNode->nama = nama;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

void hapusFrontLL() {
    del = head;
    head = head->next;
    delete del;
}

void hapusBackLL() {
    del = tail;
    cur = head;
    while (cur->next != tail)
    {
        cur = cur->next;
    }
    tail = cur;
    tail->next = NULL;
    delete del;
}

int main(int argc, char const *argv[])
{
    buatSingleLL(1234, "Iklima");
    tampilkanSingleLL();
    tambahNextLL(1235, "Dera");
    tampilkanSingleLL();
    tambahBackLL(1236, "Dandin");
    tampilkanSingleLL();
    hapusFrontLL();
    tampilkanSingleLL();
    hapusBackLL();
    tampilkanSingleLL();
    return 0;
}
