#include <bits/stdc++.h>

using namespace std;

void rev(int arr[], int size)
{
    if (size == 0)
        return;

    int last = arr[size - 1];
    rev(arr, size - 1);

    for (int i = size; i >= 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = last;
}

int main()
{
    int arr[10], t = 10;

    while (t--)
    {
        arr[t] = rand() % 10;
    }

    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
        cout << " " << arr[i];
    cout << endl;
    rev(arr, size);
    for (int i = 0; i < size; i++)
        cout << " " << arr[i];
    cout << endl;
    return 0;
}