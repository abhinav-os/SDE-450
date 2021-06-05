#include <bits/stdc++.h>
using namespace std;

void adjacency_matrix() {
    int n, m;
    cin >> n >> m;

    int mat[n+1][m+1];
    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        mat[u][v] = wt;
        mat[u][v] = wt;
    }
}

void adjacency_list() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n+1];

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void weighted_adjacency_list() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int> > adj[n+1];

    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < adj[i].size(); j++) {
            cout << "(" << adj[i][j].first << "," << adj[i][j].second << ")" << "; ";
        }
        cout << endl;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--) {
        // adjacency_matrix();
        // adjacency_list();
        weighted_adjacency_list();
    }
}

/*
1       //  Test Cases
5 6     // Number of nodes, number of edges, next 6 lines (u,v) describe that there is an edge between u,v
1 2 2   // (u, v, weight)
1 3 3
3 4 4
2 4 5
3 5 4 
4 5 2
*/