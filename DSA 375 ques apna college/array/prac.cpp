#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v;
    v = {7, 1, 5, 3, 6, 4};
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i];
    cout << endl;
    cout << v.size();
    auto it = v.begin();

    return 0;
}