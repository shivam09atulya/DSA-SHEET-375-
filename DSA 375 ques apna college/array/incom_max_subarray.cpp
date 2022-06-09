#include <bits/stdc++.h>

using namespace std;

int max_sub(int arr[], int size)
{
    int cur_sum = 0;
    int max_sum = 0;
    int aux_min = INT_MAX;
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        cur_sum += arr[i];

        if (arr[i] > 0)
            flag = 1;

        if (arr[i] < aux_min)
            aux_min = arr[i];
        if (cur_sum > max_sum)
            max_sum = cur_sum;

        else if (cur_sum < 0)
            cur_sum = 0;
    }

    if (flag == 0)
        return aux_min;

    return max_sum;
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "The max sum is " << max_sub(arr, size);
    return 0;
}