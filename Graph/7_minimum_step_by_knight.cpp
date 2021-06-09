/*
    Time Complexity: O(m*n)
    Space Complexity: O(m*n)
*/

#include <bits/stdc++.h>
using namespace std;

int bfs_util(vector<vector<bool> >& vis, vector<vector<int> >& dist, int target_x, int target_y, int x, int y, int n) {
    int dx[] = {2, 2, 1, 1, -1, -1, -2, -2};
    int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};

    vis[x][y] = true;
    dist[x][y] = 0;
    queue<pair<int, int> > q;
    q.push({x, y});

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        if(cur.first == target_x && cur.second == target_y) {
            return dist[cur.first][cur.second];
        }

        for(int j = 0; j < 8; j++) {
            int cur_pos_x = cur.first + dx[j];
            int cur_pos_y = cur.second + dy[j];
            if(cur_pos_x >= 0 && cur_pos_x < n && cur_pos_y >= 0 && cur_pos_y < n && !vis[cur_pos_x][cur_pos_y]) {
                vis[cur_pos_x][cur_pos_y] = true;
                dist[cur_pos_x][cur_pos_y] = dist[cur.first][cur.second] + 1;
                q.push({cur_pos_x, cur_pos_y});
            }
        }
    }
}

int minStepToReachTarget(vector<int>& knight_pos,vector<int>& target_pos,int n) {
    vector<vector<bool> > vis(n, vector<bool>(n, false));
    vector<vector<int> > dist(n, vector<int>(n, 0));

    int k_pos_x = n - knight_pos[1];
    int k_pos_y = knight_pos[0] - 1;
    int t_pos_x = n - target_pos[1];
    int t_pos_y = target_pos[0] - 1;  

    int ans = bfs_util(vis, dist, t_pos_x, t_pos_y, k_pos_x, k_pos_y, n);
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    vector<int> knight_pos(2,0);
    vector<int> target_pos(2,0);
    
    cin >> knight_pos[0] >> knight_pos[1] >> target_pos[0] >> target_pos[1];
    
    int foo = minStepToReachTarget(knight_pos, target_pos, n);
    cout << foo << endl;
}

/*
6
4 5
1 1
*/