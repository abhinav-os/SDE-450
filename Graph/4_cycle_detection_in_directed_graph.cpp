/*
    Time Complexity: O(V+E)
    Space Complexity: O(V+E) + O(V)
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * dfs_vis contains information about current traversal(stack)
 * if dfs_vis[ele] is true, this means ele is a part of current traversal, and hence a cycle
 * mark dfs_vis[node] as false while returning back in traversal if cycle is not found
 */

bool cycle_dfs_util(vector<vector<int> > adj, vector<bool>& vis, vector<bool>& dfs_vis, int node) {
    vis[node] = true;
    dfs_vis[node] = true;

    for(int j = 0; j < adj[node].size(); j++) {
        int ele = adj[node][j];
        if(!vis[ele]) {
            if(cycle_dfs_util(adj, vis, dfs_vis, ele))
                return true;
        } else if(dfs_vis[ele]) {
            return true;
        }
    }
    dfs_vis[node] = false;
    return false;
}

bool cycle_dfs(vector<vector<int> > adj) {
    int n = adj.size();
    vector<bool> vis(n, false);
    vector<bool> dfs_vis(n, false);
    
    for(int i = 1; i < n; i++) {
        if(!vis[i]) {
            if(cycle_dfs_util(adj, vis, dfs_vis, i))    
                return true;
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

    vector<vector<int> > adj(n+1);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    if(cycle_dfs(adj)) {
        cout << "Cycle Present";
    } else {
        cout << "No Cycles";
    }
}

/*
9 10    // Number of nodes, number of edges, next 6 lines (u,v) describe that there is an edge between u,v
1 2 
2 3
3 4
4 5
6 5
3 6
7 2
7 8
8 9
9 7
*/