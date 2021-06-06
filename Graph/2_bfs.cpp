/*
    Time Complexity: O(V+E)
    Space Complexity: O(V+E) + O(V)
*/

#include <bits/stdc++.h>
using namespace std;


void bfs(vector<vector<int> > adj) {
    int n = adj.size();

    vector<int> visited(n+1, 0);

    for(int i = 1; i < n; i++) {
        if(!visited[i]) {
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            
            while(!q.empty()) {
                int cur = q.front();
                cout << cur << " ";
                q.pop();

                for(int j = 0; j < adj[i].size(); j++) {
                    int ele = adj[i][j];
                    
                    if(!visited[ele]) {
                        visited[ele] = 1;
                        q.push(ele);
                    }
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

    int n, m;
    cin >> n >> m;

    vector<vector<int> > adj(n+1);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(adj);
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