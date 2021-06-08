/*
    Time Complexity: O(V+E)
    Space Complexity: O(V+E) + O(V)
*/

#include <bits/stdc++.h>
using namespace std;

bool cycle_dfs(vector<vector<int> > adj) {
    int n = adj.size();
    vector<bool> vis(n, false);

    for(int i = 1; i < n; i++) {
        if(!vis[i]) {
            stack<pair<int, int> > s;
            s.push({i, -1});
            vis[i] = true;

            while(!s.empty()) {
                pair<int, int> cur = s.top();
                s.pop();

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
                        s.push({ele, cur_ele});
                        vis[ele] = true;
                    }
                }
            }
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