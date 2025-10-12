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
        root->left = insert(root->left, val); // kalau lebih kecil, taruh di kiri
    }
    else if (val > root->data)
    {
        root->right = insert(root->right, val); // kalau lebih besar, taruh di kanan
    }
    return root; // balikin root-nya biar nyambung
}

/**
 * @brief Fungsi buat cari nilai paling kecil di tree
 * logikanya: karena tree ini BST, nilai terkecil pasti di paling kiri
 */
int findMinValue(Node *root)
{
    // kalau tree kosong, ya gak ada nilai
    if (root == nullptr)
    {
        return -1;
    }

    // selama masih ada anak kiri, terus turun ke kiri
    while (root->left != nullptr)
    {
        root = root->left;
    }

    // kalau udah mentok kiri, ya itu dia nilai paling kecilnya
    return root->data;
}

int main()
{
    Node *root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    cout << "Nilai terkecil dalam tree adalah: " << findMinValue(root) << endl; // harusnya keluar 20
    return 0;
}
