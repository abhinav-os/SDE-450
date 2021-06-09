/*
    Time Complexity: O(4^(n*n))
    Space Complexity: O(n*n)
*/

#include <bits/stdc++.h>
using namespace std;

void dfs_util(vector<vector<int> > maze, vector<vector<bool> >& vis, vector<string>& ans, string move, int x, int y, int n) {
    vis[x][y] = true;
    if(x == n-1 && y == n-1) {
        ans.push_back(move);
        return;
    }

    // DLRU is in lexcicographical order.
    // Dowwn
    if(x+1 < n && !vis[x+1][y] && maze[x+1][y] == 1) {
        vis[x+1][y] = true;
        dfs_util(maze, vis, ans, move + "D", x+1, y, n);
        vis[x+1][y] = false;
    }

    // Left
    if(y-1 >= 0 && !vis[x][y-1] && maze[x][y-1] == 1) {
        vis[x][y-1] = true;
        dfs_util(maze, vis, ans, move + "L", x, y-1, n);
        vis[x][y-1] = false;
    }

    // Right
    if(y+1 < n && !vis[x][y+1] && maze[x][y+1] == 1) {
        vis[x][y+1] = true;
        dfs_util(maze, vis, ans, move + "R", x, y+1, n);
        vis[x][y+1] = false;
    }

    // Up
    if(x-1 >= 0 && !vis[x-1][y] && maze[x-1][y] == 1) {
        vis[x-1][y] = true;
        dfs_util(maze, vis, ans, move + "U", x-1, y, n);
        vis[x-1][y] = false;
    }
}

vector<string> find_path(int n, vector<vector<int> >& maze) {
    vector<string> ans;
    vector<vector<bool> > vis(n, vector<bool>(n, false));

    if(maze[0][0] == 1) {
        dfs_util(maze, vis, ans, "", 0, 0, n);
    }
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    vector<vector<int> > maze(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> maze[i][j];  
    }
    
    vector<string> ans = find_path(n, maze);

    if(ans.size() == 0) {
        cout << "-1\n"; 
    } else {
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
    }

}