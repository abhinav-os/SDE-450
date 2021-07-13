/*
    Time Complexity: O(32 * N * log M)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

double median(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();

    int mini = INT_MAX, maxi = INT_MIN;
    for(int i = 0; i < n; i++) {
        mini = min(mini, mat[i][0]);
        maxi = max(maxi, mat[i][m-1]);
    }

    int low = mini, high = maxi;
    while(low <= high) {
        int mid = (low+high) >> 1;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin(); // Number of elements smaller than mid in current row;
        }

        if(cnt <= (n*m)/2) 
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
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

    cout << median(mat);
}

/*
3 3
1 3 5
2 6 9 
3 6 9
*/