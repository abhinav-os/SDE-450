/*
    Time Complexity: O(N*M)
    Space Complexity: O(N*M) ---> For returning the answer
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * dir == 0 : left --> right
 * dir == 1 : top --> down
 * dir == 2 : right --> left
 * dir == 3 : down --> top
 */

vector<int> spiralTraversal(vector<vector<int>>& a) {
    int n = a.size(), m = a[0].size();
    int left = 0, right = m-1, bottom = n-1, top = 1;
    int x = 0, y = 0, dir = 0;

    vector<int> ans;

    for(int i = 0; i < n*m; i++) {
        ans.push_back(a[x][y]);

        if(dir == 0 && y == right) {
            dir = 1;
            right -= 1;
        }

        if(dir == 1 && x == bottom) {
            dir = 2;
            bottom -= 1;
        }

        if(dir == 2 && y == left) {
            dir = 3;
            left += 1;
        }

        if(dir == 3 && x == top) {
            dir = 0;
            top += 1;
        }


        if(dir == 0)        y += 1;
        else if(dir == 1)   x += 1;
        else if(dir == 2)   y -= 1;
        else if(dir == 3)   x -= 1;
    }

    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    vector<int> ans = spiralTraversal(mat);
    for(auto ele : ans) {
        cout << ele << " "; 
    }
}

/*
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
*/