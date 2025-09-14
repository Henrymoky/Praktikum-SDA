#include <iostream>
using namespace std;

// fungsi untuk membalik array menggunakan pointer
void balikArray(int *arr, int n)
{
    int *kiri = arr;
    int *kanan = arr + n - 1;

    while (kiri < kanan)
    {
        int temp = *kiri;
        *kiri = *kanan;
        *kanan = temp;
        kiri++;
        kanan--;
    }
}

bool isPrima(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    const int n = 7;
    int arr[n];
    int count = 0, num = 2;

    // isi array dengan bilangan prima
    while (count < n)
    {
        if (isPrima(num))
        {
            arr[count] = num;
            count++;
        }
        num++;
    }

    cout << "Array sebelum dibalik: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    balikArray(arr, n);

    cout << "Array sesudah dibalik: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
