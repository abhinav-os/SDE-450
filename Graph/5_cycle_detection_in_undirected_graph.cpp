/*
    Time Complexity: O(V+E)
    Space Complexity: O(V+E) + O(V)
*/

#include <bits/stdc++.h>
using namespace std;

bool cycle_dfs_util(vector<vector<int> > adj, vector<bool>& vis, int node, int parent) {
    vis[node]=true;
    for(int j = 0; j < adj[node].size(); j++) {
        int ele = adj[node][j];
        if(!vis[ele]) {
            if(cycle_dfs_util(adj, vis, ele, node))
                return true;
        } else if(ele != parent)
            return true;
    }
    return false;
}

bool cycle_dfs(vector<vector<int> > adj) {
    int n = adj.size();
    vector<bool> vis(n, false);

    for(int i = 1; i < n; i++) {
        if(!vis[i]) {
            if(cycle_dfs_util(adj, vis, i, -1))
                return true;
        }
    }
    return false;
}

bool cycle_bfs(vector<vector<int> > adj) {
    int n = adj.size();
    vector<bool> vis(n, false);

    for(int i = 1; i < n; i++) {
        if(!vis[i]) {
            queue<pair<int, int> > q;
            q.push({i, -1});
            vis[i] = true;

            while(!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();

                int cur_ele = cur.first;
                int cur_ele_parent = cur.second;

                // cout << cur_ele << " " << cur_ele_parent << "\n";

                for(int j = 0; j < adj[cur_ele].size(); j++) {
                    int ele = adj[cur_ele][j];
                    
                    /**
                     * if element is already visited and it's not the parent of current element,
                     * that means there's a cycle.
                     */

                    if(vis[ele] && ele != cur_ele_parent) 
                        return true;

                    if(!vis[ele]) {
                        q.push({ele, cur_ele});
                        vis[ele] = true;
                    }
                }
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

    vector<vector<int> > adj(n+1);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(cycle_dfs(adj)) {
        cout << "Cycle Present";
    } else {
        cout << "No Cycles";
    }
}

/*
11 10    // Number of nodes, number of edges, next 6 lines (u,v) describe that there is an edge between u,v
1 2
2 4
3 5
5 6
6 7
7 8
8 9
9 10
5 10
8 11
*/