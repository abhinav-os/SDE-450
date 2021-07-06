/*
    Time Complexity: O(N)
    Space Complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

bool doesExist(vector<int>& a) {
    int n = a.size(), temp = 0;
    unordered_set<int> s;
    s.insert(0);
    for(int i = 0; i < n; i++) {
        temp += a[i];
        if(s.find(temp) != s.end()) 
            return true;
        s.insert(temp);
    }

    return false;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if(doesExist(a))    cout << "YES";
    else                cout << "NO";
}

/*
5
4 2 -3 1 6
*/