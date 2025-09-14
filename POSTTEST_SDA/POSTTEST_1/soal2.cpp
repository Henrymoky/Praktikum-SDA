#include <iostream>
using namespace std;

int main()
{
    const int n = 3;
    int matriks[n][n];
    int nilai = 1;

    // isi matriks dengan angka 1..9
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matriks[i][j] = nilai++;
        }
    }

    // jumlah elemen baris genap (baris ke-2 → index 1)
    int jumlah = 0;
    for (int j = 0; j < n; j++)
    {
        jumlah += matriks[1][j];
    }

    cout << "Matriks 3x3:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matriks[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "Jumlah elemen pada baris genap saja = " << jumlah << endl;

    return 0;
}
