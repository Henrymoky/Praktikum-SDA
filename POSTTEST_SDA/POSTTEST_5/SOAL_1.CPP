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

// Fungsi insert buat nambah node ke tree
Node *insert(Node *root, int val)
{
    if (root == nullptr)
    {
        return new Node(val); // kalau masih kosong, ya bikin node baru
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val); // kalau lebih kecil, taruh di kiri
    }
    else if (val > root->data)
    {
        root->right = insert(root->right, val); // kalau lebih besar, taruh di kanan
    }
    return root; // balikin root-nya
}

/**
 * @brief Fungsi buat ngitung total node dalam tree
 * logikanya: tiap node dihitung 1, terus tambahin jumlah node di kiri dan kanan
 */
int countNodes(Node *root)
{
    // kalau kosong, berarti gak ada node
    if (root == nullptr)
    {
        return 0;
    }

    // tiap node dihitung 1, terus rekursif ke kiri dan kanan
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{
    Node *root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);

    cout << "Jumlah total node dalam tree adalah: " << countNodes(root) << endl; // harusnya keluar 4
    return 0;
}
