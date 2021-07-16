/*
    Time Complexity: O(N*N)
    Space Complexity: O(N*N)
*/

#include <bits/stdc++.h>
using namespace std;

int LongestRepeatingSubsequence(string str) {
    int n = str.length();
    int dp[n+1][n+1];
    for(int i = 0; i <= n; i++) {
        dp[0][i] = 0;
        dp[i][0] = 0;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(str[i-1] == str[j-1] && i-1 != j-1)
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    
    return dp[n][n];
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    string str;
    cin >> str;
    cout << LongestRepeatingSubsequence(str);
}

/*
axxxy
*/