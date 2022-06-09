#include <bits/stdc++.h>

using namespace std;

int choclate(int arr[], int m, int size)
{
    int min = INT_MAX;
    sort(arr, arr + size);
    for (int i = 0; i <= (size - m); i++)
    {
        if (min > arr[i + m - 1] - arr[i])
            min = arr[i + m - 1] - arr[i];
    }
    return min;
}

int main()
{
    int arr[] = {3, 4, 1, 9, 56, 7, 9, 12};
    int m = 5;
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << choclate(arr, m, size);
    return 0;
}