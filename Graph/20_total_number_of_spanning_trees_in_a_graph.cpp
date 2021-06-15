/*
    Time Complexity: Polynomial for calculating co factor matrix
    Space Complexity: O(n*n)
*/

/**
 * If graph is a complete graph, ans = n^(n-2) [Cayley's Theorem]
 * In general, ans = any element of cofactor matrix of laplacian matrix. [Kirchoff's Theorem]
 * Laplacian Matrix is degree matrix - adjacency matrix. 
 */ 

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> co_factor(vector<vector<int>>& mat) {
    // Returns the co factor matrix of mat.
}

int total_spanning_tree(vector<vector<int>>& adj) {
    int n = adj.size();

    vector<vector<int>> degree(n, vector<int>(n, 0));
    vector<vector<int>> adj_matrix(n, vector<int>(n, 0));
    vector<vector<int>> laplacian(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++) {
        for(auto ele:adj[i]) {
            degree[ele][ele] += 1;
            adj_matrix[i][ele] = 1;
            adj_matrix[ele][i] = 1;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            laplacian[i][j] = degree[i][j] - adj_matrix[i][j];
        }
    }

    vector<vector<int>> cofact = co_factor(laplacian);
    return cofact[0][0];
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n, vector<int>());

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = total_spanning_tree(adj);
}

/*

*/