/*
    Time Complexity: O(m*n)
    Space Complexity: O(m*n)
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>>& grid, vector<vector<bool>>& vis, int x, int y, int row, int col) { 
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
    vis[x][y] = true;

    for(int i = 0; i < 8; i++) {
        int cur_x = x + dx[i];
        int cur_y = y + dy[i];

        if(cur_x >= 0 && cur_x < row && cur_y >= 0 && cur_y < col && grid[cur_x][cur_y] == '1' && !vis[cur_x][cur_y]) {
            dfs(grid, vis, cur_x, cur_y, row, col);
        } 
    }
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int components = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '1' && !vis[i][j]) {
                components += 1;
                dfs(grid, vis, i, j, n, m);
            }
        }
    }
    return components;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = numIslands(grid);
    cout << ans;
}

/*
4 2
0 1
1 0
1 1
1 0
*/