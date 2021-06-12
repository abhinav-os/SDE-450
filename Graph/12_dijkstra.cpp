/*
    Time Complexity: O((V+E)log V)
    Space Complexity: O(V)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> adj, int src) {
    // Priority Queue using Min-Heap, so that node with lesser distance should be on top.
    int n = adj.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n ,INT_MAX);

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        pair<int, int> foo = pq.top();
        pq.pop();

        int cur_dist = foo.first;
        int cur_node = foo.second;

        for(auto temp:adj[cur_node]) {
            int ele = temp.first;
            int dist_src = temp.second;
            if(cur_dist + dist_src < dist[ele]) {
                dist[ele] = cur_dist + dist_src;
                pq.push({dist[ele], ele});
            }
        }
    }
    return dist;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m, src;
    cin >> n >> m >> src;

    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> ans = dijkstra(adj, src);
    for(int i = 0; i < ans.size(); i++) {
        if(ans[i] == INT_MAX)
            cout << "INF\n";
        else
            cout << ans[i] << "\n";
    }
}

/*
5 6 0
0 1 2
1 2 4
2 3 3
0 3 1
1 4 5
2 4 1
*/