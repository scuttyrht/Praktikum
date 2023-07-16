/* 
    @author Zakirio Hugoraazaq Wasis
    @class TI-2B
    @date 07/06/2023
    @version 1.0
*/

#include <iostream>
using namespace std;

struct Node {
    char label;
    Node *left, *right, *parent;
};

Node *root, *newNode;

// Untuk membuat tree
void createTree (char label){
    if (root != NULL){
        std::cout <<"Tree sudah terbuat" << endl;
    }else{
        root = new Node;
        root->label = label;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        std::cout << "Berhasil mengimplementasi '" << label <<"' sebagai root."<<endl;
    }
}

// Untuk menambah child kiri
Node *insertLeft (char label, Node *node){
    if (root == NULL) {
        std::cout << "Tree belum terbuat" << endl;
        return NULL;
    } else {
        if (node->left != NULL) {
            return NULL;
        } else {
            newNode = new Node;
            newNode->label = label;
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->parent = node;
            node->left = newNode;
            std::cout << "Berhasil menambahkan '" << label <<"' sebagai child kiri '"<<newNode->parent->label << "'" << endl;

            return newNode;
        }
    }
}

// Untuk menambah anak kanan
Node *insertRight (char label, Node *node){
    if (root == NULL) {
        std::cout << "Tree belum terbuat" << endl;
        return NULL;
    } else {
        if (node->right != NULL){
            return NULL;
        } else {
            newNode = new Node;
            newNode->label = label;
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->parent = node;
            node->right = newNode;
            std::cout << "Berhasil menambahkan '" << label << "' sebagai child kanan '" <<newNode->parent->label << "'" << endl;

            return newNode;
        }
    }
}

// Untuk mengecek apakah tree kosong atau tidak
bool empty(){
    if (root == NULL) {
        return true;
    } else {
        return false;
    }
}

// Untuk meng-update node
void update (char label, Node *node) {
    if (root == NULL) {
        std::cout << "Tree belum terbuat" << endl;
    } else {
        if (node == NULL) {
            std::cout << "Node yang dipanggil tidak/belum ada" << endl;
        } else {
            char awal = node->label;
            node->label = label;
            std::cout << awal <<" ter-update menjadi " << label << endl;
        }
    }
}

// untuk mengetahui isi dari node tertentu
void retrieve(Node *node){
    if (root == NULL){
        std::cout << "Tree belum terbuat" <<endl;
    }else{
        if(node == NULL){
            std::cout <<"Node yang dipanggil tidak/belum ada"<<endl;
        }else{
            std::cout<<"Node yang dipanggil berisi: "<< node->label << endl;
        }
    }
}

// Untuk mencari node dalam tree
void find (Node *node) {
    if (root == NULL) {
        std::cout << "Tree belum terbuat" << endl;
    } else {
        std::cout << "Node\t: " << node->label << endl;
        std::cout << "Root\t: " << root->label << endl;
        if (node->parent == NULL) {
            std::cout << "Node parent\t: Tidak ada parent" << endl;
        } else {
            std::cout << "Node parent\t: " << node->parent->label << endl;
        }

        if (node->left == NULL) {
            std::cout << "Node kiri : Tidak ada" << endl;
        } else {
            std::cout << "Node kiri: " << node->left->label << endl;
        }
        if(node->right == NULL){
            std::cout << "Node kanan : Tidak ada" <<endl;
        }else{
            std::cout << "Node kanan : " << node->right->label <<endl;
        }
    }
}

// Untuk penelusuran preorder
void preOrder(Node *node = root){
    if (root == NULL) {
        std::cout << "Tree belum terbuat" <<endl;
    } else {
        if (node != NULL){
            std::cout << "'" << node->label <<"', ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

//Fungsi InOrder
void inOrder(Node *node = root){
    if (root == NULL){
        std::cout << "Tree belum terbuat" <<endl;
    } else{
        if (node != NULL){
            inOrder(node->left);
            std::cout << node->label <<", ";
            inOrder(node->right);
        }
    }
}

//Fungsi PostOrder
void postOrder(Node *node = root){
    if (root == NULL){
        std::cout << "Tree belum terbuat" << endl;
    } else{
        if (node != NULL){
            postOrder(node->left);
            postOrder(node->right);
            std::cout << node->label <<", ";
        }
    }
}

// Untuk menghapus tree
void deleteTree(Node *node){
    if (root == NULL){
        std::cout << "Tree belum terbuat"<<endl;
    } else{
        if (node != NULL){
            if (node != root){
                node->parent->left == NULL;
                node->parent->right == NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
        }
        if (node == root){
            delete root;
            root = NULL;
        }
        else{
            delete node;
        }
    }
}

// Untuk meng-clear tree
void clear(){
    if (root == NULL){
        std::cout << "Tree belum terbuat" <<endl;
    } else{
        deleteTree(root);
        std::cout << "Berhasil meng-clear tree"<<endl<<endl;
    }
}

// Untuk mengambil size tree
int size(Node *node = root){
    if (root == NULL){
        std::cout << "Tree belum terbuat" <<endl;
        return 0;
    } else{
        if (node == NULL){
            return 0;
        } else {
            return 1 + size(node->left) + size (node->right);
        }
    }
}

// Untuk menggambil height tree
int height(Node *node = root){
    if(root == NULL){
        std::cout << "Tree belum terbuat" <<endl;
        return 0;
    } else{
        if(node == NULL){
            return 0;
        } else{
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);

            if (heightKiri >= heightKanan){
                return heightKiri + 1;
            } else{
                return heightKanan + 1;
            }
        }
    }
}

// Untuk menampilkan fungsi height dan size
void characateristics() {
    if (root == NULL) {
        std::cout << "Tree belum terbuat" << endl;
    } else {
        std::cout << "Characteristic Tree:"<<endl;
        std::cout << "Height Tree\t: "<<height()<<endl;
        std::cout << "Size Tree\t: "<< size() << endl;
        std::cout << "Mean Tree\t: " << size()/height() <<endl<<endl;
    }
}



int main(){
    std::cout<<"======= Implementasi Tree ======="<<endl;
    std::cout<<"--- Zakirio  Hugoraazaq Wasis ---"<<endl;
    std::cout<<"------- 2207411039 - TI2B -------"<<endl;
    std::cout<<"================================="<<endl;
    std::cout<<endl;
    
    std::cout<<"Tree Sequences: " <<endl;
    createTree('Z');

    Node *node2, *node3, *node4, *node5, *node6, *node7, *node8, *node9, *node10, *node11, *node12;

    node2 = insertLeft('A', root);
    node3 = insertRight('K', root);
    node4 = insertRight('I', node3);
    node5 = insertLeft('R', node4);
    node6 = insertRight('O', node2);
    node7 = insertLeft('H', node6);
    node8 = insertLeft('U', node3);
    node9 = insertRight('G', node4);
    node10 = insertLeft('Q', node2);
    node11 = insertRight('W', node5);
    node12 = insertRight('S', node6);
    std::cout << endl;

    // Mengoutput penelusuran PreOrder dengan memanggil fungsi preOrder()
    std::cout<<"Penelusuran PreOrder: " <<endl;
    preOrder(root);
    std::cout<<endl<<endl;

    // Mengoutput penelusuran InOrder dengan memanggil fungsi inOrder()
    std::cout<<"Penelusuran InOrder: "<<endl;
    inOrder(root);
    std::cout<<endl<<endl;

    // Mengoutput penelusuran PostOrder dengan memanggil fungsi postOrder()
    std::cout<<"Penelusuran PostOrder: "<<endl;
    postOrder(root);
    std::cout<<endl<<endl;

    // Mengambil karakteristik dari tree
    characateristics();

    // Men-destroy keseluruhan tree
    clear();

    // Kita coba untuk memanggil karakteristik tree lagi
    characateristics();
}