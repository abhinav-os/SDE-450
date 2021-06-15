/*
    Time Complexity: O(E log E) + O(E * log(4*alpha)) ==> O(E log E)
    Space Complexity: O(N) + O(E)
*/

#include <bits/stdc++.h>
using namespace std;

void make_set(vector<int>& parent, vector<int>& rank, int n) {
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 1;
    }
}

int find_parent(int node, vector<int>& parent) {
    if(parent[node] == node) 
        return node;
    return parent[node] = find_parent(parent[node], parent);
}

void union_set(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = find_parent(u, parent);
    v = find_parent(v, parent);

    if(u < v) {
        parent[v] = u;
    } else if(v < u) {
        parent[u] = v;
    } else {
        parent[v] = u;
        rank[u] += 1;
    }
}

struct edge{
    int u;
    int v;
    int wt;

    edge(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(edge a, edge b) {
    return a.wt < b.wt;
}

vector<pair<int, int>> kruskals_mst(vector<vector<pair<int, int>>>& adj) {
    int n = adj.size();

    vector<edge> edge_list;
    for(int i = 0; i < n; i++) {
        for(auto ele:adj[i]) {
            int node = ele.first;
            int wt = ele.second;

            edge_list.push_back(edge(i, node, wt));
        }
    }

    sort(edge_list.begin(), edge_list.end(), comp);

    // DSU
    vector<int> parent(n);
    vector<int> rank(n);

    int cost = 0;
    vector<pair<int, int>> ans;

    make_set(parent, rank, n);
    for(int i = 0; i < edge_list.size(); i++) {
        edge cur_edge = edge_list[i];

        if(find_parent(cur_edge.u, parent) != find_parent(cur_edge.v, parent)) {
            union_set(cur_edge.u, cur_edge.v, parent, rank);
            cost += cur_edge.wt;
            ans.push_back({cur_edge.u, cur_edge.v});
        }
    }

    cout << cost << "\n";
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // Commenting this line to just simplify edge list representation
        // Still a undirected graph, but we are not storing both (1, 0) & (0, 1) for 0--1
        // If you don't want to do this, just check while inserting (u, v) in edge_list vector if (v, u) exists or not.
        // adj[v].push_back({u, w});   
    }

    vector<pair<int, int>> ans = kruskals_mst(adj);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}

/*
5 6
0 1 2
1 2 3
0 3 6
1 3 8
1 4 5
4 2 7
*/