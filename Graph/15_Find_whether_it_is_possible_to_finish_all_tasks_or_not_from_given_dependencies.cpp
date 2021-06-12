/*
    Time Complexity: O(V+E)
    Space Complexity: O(V)
*/

// Check Cycle, if present: NO, else YES.

#include <bits/stdc++.h>
using namespace std;

bool dfsUtil(vector<vector<int>> adj, vector<bool>& vis, vector<bool>& dfs_vis, int node) {
    vis[node] = true;
    dfs_vis[node] = true;

    for(auto ele:adj[node]) {
        if(!vis[ele]) {
            if(dfsUtil(adj, vis, dfs_vis, ele)) {
                return true;
            }
        } else if(dfs_vis[ele]) {
            return true;
        }
    }

    dfs_vis[node] = false;
    return false;
}

bool checkPossibility(vector<vector<int>> adj) {
    int n = adj.size();
    vector<bool> vis(n, false);
    vector<bool> dfs_vis(n, false);

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            if(dfsUtil(adj, vis, dfs_vis, i)) {
                return true;
            }
        }
    }
    return false;
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
        adj[v].push_back(u);
    }

    // If checkPossibility is true, means cycle is present.
    if(!checkPossibility(adj)) {
        cout << "Possible\n";
    } else {
        cout << "Not Possible\n";
    }
}

/*
4 3
1 0
2 1
3 2
*/