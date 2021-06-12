/*
    Time Complexity: O(V+E)
    Space Complexity: O(V)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> minimumTime(vector<vector<int>> adj) {
    int n = adj.size();
    vector<int> time(n, 0);

    vector<int> indegree(n, 0);

    for(int i = 0; i < n; i++) {
        for(auto ele:adj[i]) {
            indegree[ele] += 1;
        }
    }
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            q.push({i, 1});
        }
    }

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        time[cur.first] = cur.second;

        for(auto ele:adj[cur.first]) {
            indegree[ele] -= 1;
            if(indegree[ele] == 0) {
                q.push({ele, cur.second + 1});
            }
        }
    }

    return time;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n, vector<int>());
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u-=1;
        v-=1;
        adj[u].push_back(v);
    }

    vector<int> ans = minimumTime(adj);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

/*
7 7
1 2
2 3
2 4
2 5
3 6
4 6
5 7
*/