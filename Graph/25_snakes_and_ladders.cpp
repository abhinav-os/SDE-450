/*
    Time Complexity: O(n*n)
    Space Complexity: O(n*n) for boolean visited vector
*/

#include <bits/stdc++.h>
using namespace std;

pair<int, int> get_coordinates(int n, int size) {
    n -= 1;
    int y;
    int x = size - n/size - 1;
    int foo = n%(2*size);
    if(foo < size)
        y = foo;
    else
        y = (2*size - 1 - foo);

    return {x, y};
}


int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();

    int m = n*n;

    queue<pair<int, int>> q;
    q.push({1, 0});
    vector<bool> vis(m+1, false);
    vis[1] = true;

    while(!q.empty()) {
        int node = q.front().first;
        int step = q.front().second;

        q.pop();

        if(node == m) {
            return step;
        }

        for(int i = 1; i <= 6; i++) {
            int new_pos = node + i;

            if(new_pos <= m) {
                pair<int, int> new_pos_on_board = get_coordinates(new_pos, n);

                int x = new_pos_on_board.first;
                int y = new_pos_on_board.second;

                if(board[x][y] != -1) 
                    new_pos = board[x][y];

                if(!vis[new_pos]) {
                    vis[new_pos] = true;
                    q.push({new_pos, step+1});
                }
            }
        }
    }
    return -1;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int ans = snakesAndLadders(board);
    cout << ans << "\n";
}

/*
6
-1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1
-1 35 -1 -1 13 -1
-1 -1 -1 -1 -1 -1
-1 15 -1 -1 -1 -1
*/