/*
    Time Complexity: O(V+E)
    Space Complexity: O(V+E) + O(V)
*/

#include <bits/stdc++.h>
using namespace std;

void dfs_iterative(vector<vector<int> > adj) {
    int n = adj.size();

    vector<int> visited(n+1, 0);

    for(int i = 1; i < n; i++) {
        if(!visited[i]) {
            stack<int> s;
            s.push(i);
            visited[i] = 1;
            
            while(!s.empty()) {
                int cur = s.top();
                cout << cur << " ";
                s.pop();

                for(int j = 0; j < adj[cur].size(); j++) {
                    int ele = adj[cur][j];
                    
                    if(!visited[ele]) {
                        visited[ele] = 1;
                        s.push(ele);
                    }
                }
            }
        }
    }
}

void dfs(vector<vector<int> > adj, vector<bool>& visited, int node, int n) {
    for(int i = node; i < n; i++) {
        if(!visited[i]) {
            cout << i << "\n";
            visited[i] = true;
            for(int j = 0; j < adj[i].size(); j++) {
                if(!visited[adj[i][j]]) {
                    dfs(adj, visited, adj[i][j], n);
                }
            }
        }
    }
}

void dfs_util(vector<vector<int> > adj) {
    int n = adj.size(); 
    vector<bool> visited(n, false);

    dfs(adj, visited, 1, n);
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
        adj[v].push_back(u);
    }

    dfs_iterative(adj);
}

/*
7 6     // Number of nodes, number of edges, next 6 lines (u,v) describe that there is an edge between u,v
1 2
2 3
4 2
6 3
4 6
7 5
*/