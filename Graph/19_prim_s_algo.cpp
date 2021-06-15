/*
    Time Complexity: O(N+E) + O(E log N)
    Space Complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> prims_mst_brute_force(vector<vector<pair<int, int>>>& adj) {
    int n = adj.size();
    vector<int> key(n, INT_MAX);    // key[i] is weight between i and parent[i]
    vector<bool> mst_set(n, false);
    vector<int> parent(n, -1);

    key[0] = 0;

    for(int count = 0; count < n-1; count++) {
        int idx, mini = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(mst_set[i] == false && key[i] < mini) {
                mini = key[i];
                idx = i;
            }
        }

        mst_set[idx] = true;

        for(auto ele:adj[idx]) {
            int node = ele.first;
            int weight = ele.second;

            if(mst_set[node] == false && weight < key[node]) {
                key[node] = weight;
                parent[node] = idx;
            }
        }
    }

    int total_weight_of_MST = 0;
    vector<pair<int, int>> ans;
    for(int i = 1; i < n; i++) {
        total_weight_of_MST += key[i];
        ans.push_back({parent[i], i});
    }

    cout << total_weight_of_MST << "\n";
    return ans;
}

vector<pair<int, int>> prims_mst(vector<vector<pair<int, int>>>& adj) {
    int n = adj.size();

    vector<int> key(n, INT_MAX);
    vector<bool> mst_set(n, false);
    vector<int> parent(n, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({0, 0});
    key[0] = 0;

    while(!pq.empty()) {
        int idx = pq.top().second;
        pq.pop();

        mst_set[idx] = true;

        for(auto ele:adj[idx]) {
            int node = ele.first;
            int weight = ele.second;
            if(mst_set[node] == false && weight < key[node]) {
                key[node] = weight;
                parent[node] = idx;
                pq.push({key[node], node});
            }
        }
    }

    int total_weight_of_MST = 0;
    vector<pair<int, int>> ans;
    for(int i = 1; i < n; i++) {
        total_weight_of_MST += key[i];
        ans.push_back({parent[i], i});
    }

    cout << total_weight_of_MST << "\n";
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
        int u, v, wt;
        cin >> u >> v >> wt;       
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<pair<int, int>> ans = prims_mst(adj);
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