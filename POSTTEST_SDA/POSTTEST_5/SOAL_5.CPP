#include <iostream>
using namespace std;

// Struktur Node buat Binary Tree
struct Node
{
    int data;
    Node *left;
    Node *right;

    // constructor biar gampang bikin node baru
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Fungsi insert buat nambah data ke tree
Node *insert(Node *root, int val)
{
    if (root == nullptr)
    {
        return new Node(val); // kalau kosong ya bikin node baru
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val); // kalau lebih kecil, masuk ke kiri
    }
    else if (val > root->data)
    {
        root->right = insert(root->right, val); // kalau lebih besar, masuk ke kanan
    }
    return root; // balikin root biar nyambung
}

/**
 * @brief Fungsi buat traversal pre-order
 * urutannya: root → kiri → kanan
 */
void preOrderTraversal(Node *root)
{
    // kalau kosong, ya udah balik
    if (root == nullptr)
    {
        return;
    }

    // cetak dulu isi node sekarang
    cout << root->data << " ";

    // habis itu jalanin yang kiri
    preOrderTraversal(root->left);

    // terakhir jalanin yang kanan
    preOrderTraversal(root->right);
}

int main()
{
    Node *root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Pre-order traversal dari tree adalah: ";
    preOrderTraversal(root); // harusnya keluar: 50 30 20 40 70 60 80
    cout << endl;
    return 0;
}
