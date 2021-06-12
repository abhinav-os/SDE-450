/*
    Time Complexity: O(V+E)
    Space Complexity: O(V+E) + O(V)
*/

/**
 * Number of nodes = n
 * Number of edges = m
 * Minimum number of edges required to connect n nodes = n-1
 * If n-1 > m, it's not possible to connect all nodes together
 * Number of nodes with 0 edges = x
 * Minimum number of edges required to connect x edges = x-1
 * Number of connected components = y
 * Number of connected components with nodes > 0 = y-x
 * Total number of edges required to make graph connected = (x-1)+(y-x) = (y-1) 
 */

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int> > adj, vector<bool>& vis, int node) {
    vis[node] = true;

    for(int j = 0; j < adj[node].size(); j++) {
        int ele = adj[node][j];
        if(!vis[ele]) {
            dfs(adj, vis, ele);
        }
    }
}

int makeConnected(int n, vector<vector<int> >& connections) {
    int edges = connections.size();

    if(n-1 > edges)
        return -1;
    
    vector<bool> vis(n, false);
    vector<vector<int> > adj(n, vector<int>());

    for(int i = 0; i < edges; i++) {
        int u = connections[i][0];
        int v = connections[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int connected_components = 0;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            connected_components += 1;
            dfs(adj, vis, i);
        }
    }

    return connected_components-1;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    vector<vector<int> > edge_list(m, vector<int>(2));
    for(int i = 0; i < m; i++) {
        cin >> edge_list[i][0] >> edge_list[i][1];
    }

    int ans = makeConnected(n, edge_list);
    cout << ans << "\n"; 
}

/*
6 5
0 1
0 2
0 3
1 2 
1 3
*/