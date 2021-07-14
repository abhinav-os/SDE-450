/*
    Time Complexity: O(N*M)
    Space Complexity: O(M)
*/

#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& a) {
    int n = a.size();
    vector<int> pse_index(n), nse_index(n);
    stack<pair<int, int>> s1;   // {val, index}
    for(int i = 0; i < n; i++) {
        while(!s1.empty() && s1.top().first >= a[i])
            s1.pop();

        if(s1.empty())
            pse_index[i] = -1;
        else
            pse_index[i] = s1.top().second;

        s1.push({a[i], i});
    }

    stack<pair<int, int>> s2;   // {val, index}
    for(int i = n-1; i >= 0; i--) {
        while(!s2.empty() && s2.top().first >= a[i])
            s2.pop();

        if(s2.empty())
            nse_index[i] = n;
        else
            nse_index[i] = s2.top().second;

        s2.push({a[i], i});
    }

    int max_area = 0;
    for(int i = 0; i < n; i++) {
        max_area = max(max_area, (nse_index[i] - pse_index[i] - 1) * a[i]);
    }

    return max_area;
}

int maxArea(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size(), ans = 0;
    
    vector<int> cur_histogram(m, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == 0)
                cur_histogram[j] = 0;
            else
                cur_histogram[j] += 1;
        }
        ans = max(ans, largestRectangleArea(cur_histogram));
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

    cout << maxArea(mat);
}

/*
4 4 
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
*/