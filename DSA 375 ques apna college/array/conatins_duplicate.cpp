#include <bits/stdc++.h>

using namespace std;

bool dup(int arr[], int size)
{
    map<int, int> m;

    for (int i = 0; i < size; i++)
    {
        m[arr[i]]++;
    }

    for (auto it : m)
    {
        if (it.second > 1)
            return true;
    }

    return false;
}

int main()
{
    int arr[] = {1, 5, -2, -4, 0, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << " " << dup(arr, size);
    return 0;
}