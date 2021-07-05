/*
    Time Complexity: O(N1 + N2 + N3)
    Space Complexity: O(N1 + N2 + N3)
*/

/**
 * OR, simply use unordered_map.
 */ 

#include <bits/stdc++.h>
using namespace std;

vector<int> commonElements(vector<int>& a, vector<int>& b, vector<int>& c) {
    int n1 = a.size(), n2 = b.size(), n3 = c.size();
    vector<int> ans, temp;

    int i = 0, j = 0;
    while(i < n1 && j < n2) {
        if(a[i] < b[j]) {
            i += 1;
        } else if(a[i] > b[j]) {
            j += 1;
        } else {
            temp.push_back(a[i]);
            int cur = a[i];
            while(a[i] == b[j] && a[i] == cur && i < n1 && j < n2) {
                i += 1;
                j += 1;
            }
        }
    }

    int n = temp.size();
    i = 0, j = 0;

    while(i < n && j < n3) {
        if(temp[i] < c[j]) {
            i += 1;
        } else if(temp[i] > c[j]) {
            j += 1;
        } else {
            ans.push_back(temp[i]);
            int cur = temp[i];
            while(temp[i] == c[j] && c[j] == cur && i < n && j < n3) {
                i += 1;
                j += 1;
            }
        }
    }

    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    vector<int> a(n1), b(n2), c(n3);
    
    for(int i = 0; i < n1; i++)      cin >> a[i];
    for(int i = 0; i < n2; i++)      cin >> b[i];
    for(int i = 0; i < n3; i++)      cin >> c[i];

    vector<int> ans = commonElements(a, b, c);
    for(auto ele : ans) {
        cout << ele << " ";
    }
}

/*
6 5 8
1 5 10 20 40 80
6 7 20 80 100
3 4 15 20 30 70 80 120
*/