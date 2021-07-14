/*
    Time Complexity: O(N*M)
    Space Complexity: O(N*M)
*/

#include <bits/stdc++.h>
using namespace std;

int maxValue(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> maxi(n, vector<int>(m, 0));

    maxi[n-1][m-1] = mat[n-1][m-1];

    // Filling last column & row
    for(int i = n-2; i >= 0; i--)   maxi[i][m-1] = max(maxi[i+1][m-1], mat[i][m-1]);
    for(int j = m-2; j >= 0; j--)   maxi[n-1][j] = max(maxi[n-1][j+1], mat[n-1][j]);

    for(int i = n-2; i >= 0; i--) {
        for(int j = m-2; j >= 0; j--) {
            maxi[i][j] = max({mat[i][j], maxi[i+1][j], maxi[i][j+1]});
        }
    }

    int ans = INT_MIN;
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-1; j++) {
            ans = max(ans, maxi[i+1][j+1] - mat[i][j]);
        }
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

    cout << maxValue(mat);
}

/*
5 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 6 1 3 
-4 -1 1 7 -6
0 -4 10 -5 1 r
*/