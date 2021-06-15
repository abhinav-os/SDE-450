/*
    Time Complexity: O(N*E)
    Space Complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

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

void bellman_ford(vector<edge>& edge_list, int src, int n) {
    int m = edge_list.size();
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < m; j++) {
            int x = edge_list[j].u;
            int y = edge_list[j].v;
            int weight = edge_list[j].wt;

            if(dist[x] != INT_MAX && dist[x] + weight < dist[y]) {
                dist[y] = dist[x] + weight;
            }
        }
    }

    for(int j = 0; j < m; j++) {
            int x = edge_list[j].u;
            int y = edge_list[j].v;
            int weight = edge_list[j].wt;

            if(dist[x] + weight < dist[y]) {
                cout << "Negative Cycle Present\n";
            }
    }

    for(int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m, src;
    cin >> n >> m >> src;

    vector<edge> edge_list;
    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edge_list.push_back(edge(u, v, wt));
    }

    bellman_ford(edge_list, src, n);
}

/*
6 7 0
0 1 5
1 2 -2
1 5 -3
2 4 3
3 2 6
3 4 -2
5 3 1
*/