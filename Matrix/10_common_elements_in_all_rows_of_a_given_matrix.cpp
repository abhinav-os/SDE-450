/*
    Time Complexity: O(N*M)
    Space Complexity: O(N*M)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> commonElements(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();

    unordered_map<int, int> mp;
    for(int j = 0; j < m; j++) 
        mp[mat[0][j]] = 1;

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mp[mat[i][j]] == i)
                mp[mat[i][j]] = i+1;
        }
    }

    vector<int> ans;
    for(auto itr = mp.begin(); itr != mp.end(); itr++) {
        if(itr->second == n)
            ans.push_back(itr->first);
    }
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    vector<int> ans = commonElements(mat);
    for(auto ele : ans) {
        cout << ele << " ";
    }
}

/*
4 5
1 2 1 4 8
3 7 8 5 1
8 7 7 3 1
8 1 2 7 9
*/