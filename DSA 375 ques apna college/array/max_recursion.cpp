#include <bits/stdc++.h>

using namespace std;

int find_minmax(int a[], int low, int high)
{
    if (low == high)
        return a[low];

    if (low > high)
        return -1;

    int mid = (low + high) / 2;
    int rmax = find_minmax(a, low, mid);
    int lmax = find_minmax(a, mid + 1, high);

    if (rmax >= lmax)
        return rmax;

    else if (lmax > rmax)
        return lmax;

    return -1;
}

int main()
{
    int a[10000], t = 10000;

    while (t--)
    {
        a[t] = rand() % 10000;
    }
    int size = sizeof(a) / sizeof(a[0]);
    cout << find_minmax(a, 0, size);

    return 0;
}

// int find_max(int a[], int size)
// {
//     if (size == 0)
//         return -1;

//     int max_no = find_max(a, size - 1);

//     if (a[size - 1] > max_no)
//         return a[size - 1];
//     else
//         return max_no;
// }

// int main()
// {
//     int a[10000], t = 10000;

//     while (t--)
//     {
//         a[t] = rand() % 10000;
//     }
//     int size = sizeof(a) / sizeof(a[0]);
//     cout << find_max(a, size);

//     return 0;
// }
