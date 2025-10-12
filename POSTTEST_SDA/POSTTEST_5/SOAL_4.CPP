#include <iostream>
using namespace std;

// Struktur Node buat Binary Tree
struct Node
{
    int data;
    Node *left;
    Node *right;

    // Constructor biar gampang bikin node baru
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Fungsi insert buat bangun tree
Node *insert(Node *root, int val)
{
    if (root == nullptr)
    {
        return new Node(val); // kalau kosong, ya buat node baru
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
 * @brief Fungsi buat traversal post-order
 * urutannya: kiri → kanan → root
 */
void postOrderTraversal(Node *root)
{
    // kalau kosong, ya udahan aja
    if (root == nullptr)
    {
        return;
    }

    // kunjungi yang kiri dulu
    postOrderTraversal(root->left);

    // habis itu baru yang kanan
    postOrderTraversal(root->right);

    // terakhir baru cetak data dari node sekarang
    cout << root->data << " ";
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

    cout << "Post-order traversal dari tree adalah: ";
    postOrderTraversal(root); // hasilnya harus: 20 40 30 60 80 70 50
    cout << endl;
    return 0;
}
