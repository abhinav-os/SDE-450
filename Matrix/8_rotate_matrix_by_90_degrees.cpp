/*
    Time Complexity: O(N*M)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

void rotateBy90Deg(vector<vector<int>>& mat) {
    int n = mat.size();

    for(int i = 0; i < n/2; i++) {
        for(int j = 0; j < (n+1)/2; j++) {
            int temp = mat[n-j-1][i];
            mat[n-j-1][i] = mat[n-i-1][n-j-1];
            mat[n-i-1][n-j-1] = mat[j][n-i-1];
            mat[j][n-i-1] = mat[i][j];
            mat[i][j] = temp;
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    rotateBy90Deg(mat);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

/*
3
1 2 3 
4 5 6
7 8 9
*/