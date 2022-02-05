/*
    Time Complexity: theta(n)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

void rotate_left(vector<int> a, int k)
{
    rotate(a.begin(), a.begin() + k, a.end());
    for (auto ele : a)
    {
        cout << ele << " ";
    }
    cout << endl;
}

void rotate_right(vector<int> a, int k)
{
    int n = a.size();
    rotate(a.begin(), a.begin() + n - k, a.end());
    for (auto ele : a)
    {
        cout << ele << " ";
    }
    cout << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    rotate_left(a, 3);
    rotate_right(a, 3);
}

/*
9
1 2 3 4 5 6 7 8 9
*/