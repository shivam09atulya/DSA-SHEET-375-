#include <bits/stdc++.h>

using namespace std;

class ans
{
public:
    int maximum;
    int minimum;
};

ans max_min(int a[], int size)
{
    int max = a[0];
    int min = a[0];

    for (int i = 0; i < size; i++)
        if (a[i] >= max)
            max = a[i];

    for (int i = 0; i < size; i++)
        if (a[i] <= min)
            min = a[i];

    ans now;
    now.maximum = max;
    now.minimum = min;

    return now;
}

int main()
{
    int a[10];

    int t = 10;
    while (t--)
    {
        a[t] = rand() % 100;
    }
    int size = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < 10; i++)
        cout << " " << a[i];
    cout << endl;
    class ans here;
    here = max_min(a, size);

    cout << "Max element is " << here.maximum << endl;
    cout << "Min element is " << here.minimum << endl;

    return 0;
}