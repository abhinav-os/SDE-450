/*
    Time Complexity: O(m+n)
    Space Complexity: O(min(m, n))
*/

/*
Handles Duplicates
*/

#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

void intersection(vector<int> a, vector<int> b)
{
    unordered_set<int> s;
    int n = a.size();
    int m = b.size();

    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] == b[j])
        {
            if (s.find(a[i]) != s.end())
            {
                i += 1;
                j += 1;
            }
            else
            {
                s.insert(a[i]);
                i += 1;
                j += 1;
            }
        }
        else if (a[i] < b[j])
        {
            i += 1;
        }
        else
        {
            j += 1;
        }
    }

    for (auto ele : s)
    {
        cout << ele << " ";
    }
}

void unionn(vector<int> a, vector<int> b)
{
    unordered_set<int> s;
    int n = a.size();
    int m = b.size();

    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
    }

    for (int j = 0; j < m; j++)
    {
        s.insert(b[j]);
    }

    for (auto ele : s)
    {
        cout << ele << " ";
    }
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

    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    intersection(a, b);
    cout << "\n";
    unionn(a, b);
}

/*
5
1 2 2 3 5
6
2 3 3 5 7 10
*/