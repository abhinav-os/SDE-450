/*
    Time Complexity: O(m*n)
    Space Complexity: O(m*n)
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor) {
    int m = image.size();
    int n = image[0].size();
    vector<vector<bool> > vis(m, vector<bool>(n, false));

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    queue<pair<int, int> > q;
    vis[sr][sc] = true;
    q.push({sr, sc});

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        // Process cur, first color its surrounding if they have same color as parent, then color parent to newColor

        for(int j = 0; j < 4; j++) {
            int cur_new_x = cur.first + dx[j];
            int cur_new_y = cur.second + dy[j];
            if(cur_new_x >= 0 && cur_new_x < m && cur_new_y >= 0 && cur_new_y < n && !vis[cur_new_x][cur_new_y] && image[cur_new_x][cur_new_y] == image[cur.first][cur.second]) {
                vis[cur_new_x][cur_new_y] = true;
                q.push({cur_new_x, cur_new_y});
            }
        }

        image[cur.first][cur.second] = newColor;
    }

    return image;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int m, n;
    cin >> m >> n;

    vector<vector<int> > image(m, vector<int>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) 
            cin >> image[i][j];
    }

    int sr, sc, new_color;
    cin >> sr >> sc >> new_color;
    
    vector<vector<int> > ans = floodFill(image, sr, sc, new_color);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cout << image[i][j] << " ";
        cout << endl;
    }
}

/*
3 3 
1 1 1
1 1 0
1 0 1
1 1
2
*/