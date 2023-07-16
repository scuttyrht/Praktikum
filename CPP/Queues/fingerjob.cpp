#include <iostream>


// Zakirio Hugoraazaq Wasis - Absen 9

struct buku {
    int id, tahun_terbit;
    std::string judul, penulis, penerbit;
    buku *next;
};

buku *head, *tail, *new_node, *cur, *del;
int max = 5;

int count() {
    if (head == NULL) return 0;
    else {
        int amt = 0;
        cur = head;
        while (cur != NULL) {
            cur = cur->next;
            amt++;
        }
        return amt;
    }
}

bool isEmpty() {
    if(count() == 0) return true;
    else return false;
}

bool isFull() {
    if (count() == max) return true;
    else return false;
}

void enqueue(int data[2], std::string judul, std::string penulis, std::string penerbit) {
    if (isFull()) {
        std::cout << "Queue sudah penuh\n\n";
    } else {
        if (isEmpty()) {
            head = new buku();
            head->id = data[0];
            head->judul = judul;
            head->penulis = penulis;
            head->penerbit = penerbit;
            head->tahun_terbit = data[1];
            head->next = NULL;
            tail = head;
        } else {
            new_node = new buku();
            new_node->id = data[0];
            new_node->judul = judul;
            new_node->penulis = penulis;
            new_node->penerbit = penerbit;
            new_node->tahun_terbit = data[1];
            new_node->next = NULL;
            tail->next = new_node;
            tail = new_node;
        }
    }
}

void dequeue() {
    if (isEmpty()) {
        std::cout << "Tidak ada data untuk dihapus\n\n";
    } else {
        del = head;
        head = head->next;
        del->next = NULL;
        delete del;
    }
}

void display() {
    std::cout << "Data Queue Buku:\n-----------------------------";
    cur = head;
    while (cur != NULL) {
        std::cout << "\nID\t\t: " << cur->id
        << "\nJudul\t\t: " << cur->judul
        << "\nPenulis\t\t: " << cur->penulis
        << "\nPenerbit\t: " << cur->penerbit
        << "\nTahun Terbit\t: " << cur->tahun_terbit
        << std::endl;
        cur = cur->next;
    }
    
    std::cout << "\nJumlah buku dalam antrian: " << count() <<
    std::endl << "-----------------------------\n\n";
}

void destroy() {
    if (isEmpty()) {
        std::cout << "Queue sudah kosong\n";
    } else {
        cur = head;
        while (cur != NULL) {
            del = cur;
            cur = cur->next;
            del->next = NULL;
            delete del;
        }
        head = NULL;
        tail = NULL;
    }
    
}

int main(int argc, char const *argv[])
{
    dequeue();

    int buku1[2] = {1000, 1960};
    enqueue(buku1, "To Kill a Mocking Bird", "Harper Lee", "J.B. Lippincott & Co.");
    display();

    int buku2[2] = {1001, 1949};
    enqueue(buku2, "1984", "George Orwell", "Secker & Warburg");

    int buku3[2] = {1002, 1925};
    enqueue(buku3, "The Great Gatsby", "F. Scott Fitzgerald", "Charles Scribner's Sons");

    int buku4[2] = {1003, 1813};
    enqueue(buku4, "Pride and Prejudice", "Jane Austen", "T. Egerton, Whitehall");

    int buku5[2] = {1004, 1951};
    enqueue(buku5, "The Catcher in the Rye", "J.D. Salinger", "Little, Brown and Company");
    display();

    int buku6[2] = {1005, 1988};
    enqueue(buku6, "The Alchemist", "Paulo Coelho", "HarperOne");
    display();

    dequeue();

    int buku7[2] = {1006, 2003};
    enqueue(buku7, "The Da Vinci Code", "Dan Brown", "Doubleday");
    display();

    destroy();
    display();

    int buku8[2] = {1007, 1950};
    enqueue(buku8, "The Chronicles of Narnia: The Lion, the Witch, and the Wardrobe", "C.S. Lewis", "Geoffrey Bles");
    display();

    system("PAUSE");

    return 0;
}
