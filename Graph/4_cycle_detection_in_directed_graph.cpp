/*
    Time Complexity: O(V+E)
    Space Complexity: O(V+E) + O(V)
*/

#include <bits/stdc++.h>
using namespace std;

bool cycle_bfs(vector<vector<int> > adj) {

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

    if(cycle_bfs(adj)) {
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