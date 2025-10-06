## SOAL 2

Buat fungsi yang memeriksa apakah sebuah string yang berisi tanda kurung (), {}, dan [] seimbang. Contohnya, "{[()]}" seimbang, tetapi "{[(])}" tidak. Gunakan implementasi Stack manual.

Struktur Data:

```c++
#include <iostream>
#include <string>
using namespace std;

// Struktur node buat stack
struct Node {
    char data;
    Node* next;
};

// Fungsi push (masukin data ke stack)
void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

// Fungsi pop (ngeluarin data paling atas dari stack)
char pop(Node*& top) {
    if (top == nullptr) return '\0'; // kalau stack kosong, return karakter kosong
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

// Fungsi buat ngecek apakah tanda kurung seimbang atau nggak
bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;

    // --- LENGKAPI DI SINI ---
    // Loop semua karakter di string expr
    for (char c : expr) {
        // 1. Kalau ketemu kurung buka, masukin ke stack
        if (c == '(' || c == '{' || c == '[') {
            push(stackTop, c);
        }
        // 2. Kalau ketemu kurung tutup, cek pasangannya
        else if (c == ')' || c == '}' || c == ']') {
            // a. Kalau stack kosong, berarti nggak ada pasangan -> false
            if (stackTop == nullptr) return false;

            // b. Ambil kurung buka terakhir dari stack
            char topChar = pop(stackTop);

            // c. Cek apakah cocok dengan kurung tutupnya
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false; // kalau beda, berarti nggak seimbang
            }
        }
    }

    // 3. Setelah semua karakter dicek, kalau stack kosong berarti seimbang
    bool balanced = (stackTop == nullptr);

    // Bersihkan sisa node biar gak bocor
    while (stackTop != nullptr) pop(stackTop);

    return balanced;
    // --- LENGKAPI DI SINI ---
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;
    // Expected output: Seimbang

    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;
    // Expected output: Tidak Seimbang

    // Komentar tambahan versi saya:
    // - Kalau nemu kurung buka, kita simpen dulu di stack.
    // - Kalau nemu kurung tutup, kita cek apakah yang terakhir masuk cocok sama dia.
    // - Kalau semua pasangan cocok dan gak ada sisa kurung buka di stack, berarti seimbang.
    // Stack di sini bantu ngatur urutan buka-tutup biar gak berantakan.

    return 0;
}


Hanya Info:

Stack digunakan untuk menyimpan kurung buka. Setiap kali menemukan kurung tutup, kita memeriksa apakah kurung buka terakhir di stack adalah pasangannya.

---
```
