## SOAL 1

Buat sebuah fungsi yang menerima string dan mengembalikannya dalam keadaan terbalik. Anda harus menggunakan struktur data Stack yang diimplementasikan secara manual menggunakan singly linked list.

Struktur Data:

```c++
#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

// Fungsi push -> buat masukin karakter ke dalam stack
void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

// Fungsi pop -> buat ngeluarin karakter paling atas dari stack
char pop(Node*& top) {
    if (top == nullptr) return '\0'; // kalau stack kosong, balikin karakter kosong
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

// Fungsi untuk membalik string pakai stack manual
string reverseString(string s) {
    Node* stackTop = nullptr;
    string reversed = "";

    // --- LENGKAPI DI SINI ---
    // 1. Masukkan semua karakter dari string ke dalam stack (push satu per satu)
    for (char c : s) {
        push(stackTop, c);
        // jadi setiap huruf yang masuk akan numpuk ke atas
    }

    // 2. Keluarkan semua karakter dari stack (pop) dan tambahkan ke string hasil
    while (stackTop != nullptr) {
        reversed += pop(stackTop);
        // huruf yang terakhir masuk akan keluar duluan -> otomatis jadi kebalik
    }
    // --- LENGKAPI DI SINI ---

    return reversed; // balikin string hasil yang udah dibalik
}

int main() {
    string text = "Struktur Data";
    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl;
    // Output: ataD rutkurtS

    // Komentar tambahan dari saya:
    // kita masukin dulu semua huruf ke dalam stack satu-satu.
    // Karena sistem stack itu LIFO (Last In, First Out),
    // huruf yang terakhir dimasukin bakal keluar duluan waktu di-pop.
    // Nah urutan itulah yang bikin string-nya otomatis kebalik.

    return 0;
}


Hanya Info:

Karena sifat Stack adalah LIFO (Last-In, First-Out), karakter terakhir yang dimasukkan akan menjadi yang pertama kali dikeluarkan. Ini secara alami membalik urutan karakter.

---





```
