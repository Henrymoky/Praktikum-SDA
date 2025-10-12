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
        return new Node(val); // kalau masih kosong, ya buat node baru
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
 * @brief Fungsi buat cari nilai paling besar di tree
 * logikanya: karena ini BST, nilai paling besar pasti di paling kanan
 */
int findMaxValue(Node *root)
{
    // kalau tree kosong, ya gak ada nilai
    if (root == nullptr)
    {
        return -1;
    }

    // selama masih ada anak kanan, terus aja geser ke kanan
    while (root->right != nullptr)
    {
        root = root->right;
    }

    // kalau udah mentok kanan, berarti itu nilai paling besar
    return root->data;
}

int main()
{
    Node *root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 80);

    cout << "Nilai terbesar dalam tree adalah: " << findMaxValue(root) << endl; // harusnya keluar 80
    return 0;
}
