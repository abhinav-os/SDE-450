/*
    Time Complexity: O(N+M)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();

    int col = m-1, row = 0;
    for(int i = 0; i < n; i++) {
        if(mat[i][m-1] == 1) {
            row = i;
            break;
        }

        if(i == n-1)
            return -1;
    }

    int ans = row;

    for(int j = 0; j < m; j++) {
        if(mat[row][j] == 1) {
            col = j;
            break;
        }
    }

    for(int i = row + 1; i < n; i++) {
        if(mat[i][col-1] == 1 && col > 0) {
            int j = col-1;
            while(j >= 0 && mat[i][j] == 1) {
                col = j;
                j -= 1;
            }
            ans = i;
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

    cout << rowWithMax1s(mat);
}

/*
4 4 
0 1 1 1
0 0 1 1
1 1 1 1
0 0 0 0
*/