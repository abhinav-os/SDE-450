/*
    Time Complexity: O(N*N + E)
    Space Complexity: O(N)
*/

/**
 * Chromatic Number: Number of colours used to colour the graph such that no two adjacent vertes is of same colour.
 * Chromatic Number will be always <= d+1, where d is the maximum degree in the graph.
 * NP-Complete Pronlem.
 * Below implementation is a basic greedy approach.
 * Doesn't guarantee minimum number of colours.
 * The number of colors used sometime depend on the order in which vertices are processed.
 * The most common algorithm which performs better than the basic algorithm is Welsh–Powell Algorithm which considers vertices in descending order of degrees
 */ 


#include <bits/stdc++.h>
using namespace std;

vector<int> graph_coloring(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> colour(n, -1);
    vector<bool> available(n, true);

    colour[0] = 0;

    for(int i = 1; i < n; i++) {
        for(auto ele:adj[i]) {
            if(colour[ele] != -1) {
                available[colour[ele]] = false;
            }
        }

        for(int j = 0; j < n; j++) {
            if(available[j]) {
                colour[i] = j;
                break;
            }
        }

        for(auto ele:adj[i]) {
            if(colour[ele] != -1) {
                available[colour[ele]] = true;
            }
        }
    }

    return colour;
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
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans = graph_coloring(adj);
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}

/*
5 6
0 1
0 2
1 2 
1 3
2 3
3 4
*/