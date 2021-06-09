/*
    Time Complexity: O(V+E)
    Space Complexity: O(V)
*/
#include <bits/stdc++.h>
using namespace std;

/**
 * Applicable only for directed acyclic graph
 * DFS Approach: Just put nodes in stack after it is visited so that it will come first if we reverse it.
 * BFS Approach: Kahn's Algorithm, store indegree.
 */ 

vector<int> topological_sort_bfs(vector<vector<int> > adj) {
    int n = adj.size();
    vector<int> indegree(n, 0);
    vector<int> ans;

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < adj[i].size(); j++) {
            indegree[adj[i][j]] += 1;
        }
    }

    queue<int> q;
    for(int i = 1; i < n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int cur = q.front();
        ans.push_back(cur);
        q.pop();

        for(int j = 0; j < adj[cur].size(); j++) {
            int ele = adj[cur][j];
            indegree[ele] -= 1;
            if(indegree[ele] == 0) {
                q.push(ele);
            }
        }
    }

    return ans;
}

void topological_sort_dfs_util(vector<vector<int> > adj, vector<bool>& vis, stack<int>& s, int node) {
    vis[node] = true;
    
    for(int j = 0; j < adj[node].size(); j++) {
        int ele = adj[node][j];

        if(!vis[ele]) {
            topological_sort_dfs_util(adj, vis, s, ele);
        }
    }
    s.push(node);
}

vector<int> topological_sort_dfs(vector<vector<int> > adj) {
    int n = adj.size(); 
    vector<bool> vis(n, false);
    stack<int> s;

    for(int i = 1; i < n; i++) {
        if(!vis[i]) 
            topological_sort_dfs_util(adj, vis, s, i);
    }

    vector<int> ans;

    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
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

    vector<vector<int> > adj(n+1);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    vector<int> ans = topological_sort_bfs(adj);
    for(int i = 0; i < ans.size(); i++) 
        cout << ans[i] << " ";
}

/*
6 6
6 1
5 1
6 3
5 2
3 4
4 2
*/