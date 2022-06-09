#include <bits/stdc++.h>

using namespace std;

void next_perm(vector<int> &v)
{
    int min_pos = 0, min = INT_MAX, flag = 0, max_ele = INT_MIN, max_pos = 0;

    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (v[i] < min)
        {
            min = v[i];
            min_pos = i;
        }

        if (v[i] > max_ele)
        {
            max_ele = v[i];
            max_pos = i;
        }

        if (v[i - 1] < min)
        {
            int temp = v[i - 1];
            v[i - 1] = min;
            v[min_pos] = temp;
            flag = 1;

            if (max_ele != INT_MIN)
            {
                temp = v[max_pos];
                v[max_pos] = v[min_pos];
                v[min_pos] = temp;
            }
            break;
        }
    }

    if (flag == 0)
    {
        sort(v.begin(), v.end());
    }
}

int main()
{
    vector<int> v = {1, 3, 2};

    next_perm(v);
    for (auto it : v)
        cout << it;
    return 0;
}