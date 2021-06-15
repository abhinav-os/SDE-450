/*
    Time Complexity: O(N*N*N)
    Space Complexity: O(1) or O(N*N) Depending upon implementation
*/

#include <bits/stdc++.h>
using namespace std;

void floyd_warshall(vector<vector<int>>& adj_mat) {
    int n = adj_mat.size();

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(adj_mat[i][k] != INT_MAX && adj_mat[k][j] != INT_MAX && adj_mat[i][j] > adj_mat[i][k] + adj_mat[k][j]) {
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                }
            }
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    vector<vector<int>> adj_mat(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> adj_mat[i][j];
            adj_mat[i][j] = (adj_mat[i][j]==-1) ? INT_MAX : adj_mat[i][j];
        }
    }

    floyd_warshall(adj_mat);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << ((adj_mat[i][j]==INT_MAX) ? -1 : adj_mat[i][j]) << " ";
        }
        cout << "\n";
    }
}

/*
4
0 5 -1 10
-1 0 3 -1
-1 -1 0 1
-1 -1 -1 0
*/