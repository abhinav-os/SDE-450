/*
    Time Complexity: O(N*K)
    Space Complexity: O(K)
*/

/**
 * Recurrence Relation:
 * Profit on ith day with atmost k transcation = dp[k][i] = max(dp[k][i-1], a[i]-a[j]+dp[k-1][j]); 0 <= j <= i
 * 
 * That means maximum of(Not doing any transaction on day i, selling on day i the stock bought on day j)
 */ 

#include <bits/stdc++.h>
using namespace std;

/**
 * Column Wise filling
 * Time Complexity: O(N*K)
 * Space Complexity: O(N)
 */ 

int maximumProfit(vector<int>& a, int k) {
    int n = a.size();
    if(n < 2) 
        return 0;
        
    vector<int> dp(k+1, 0);
    vector<int> mini(k+1, a[0]);

    for(int j = 1; j < n; j++) {
        for(int i = 1; i <= k; i++) {
            mini[i] = min(mini[i], a[j] - dp[i-1]);
            dp[i] = max(dp[i], a[j] - mini[i]);
        }
    }

    return dp[k];
}



/**
 * Time Complexity: O(N*K)
 * Space Complexity: O(N*K)
 */ 

/*
int maximumProfit(vector<int>& a, int k) {
    int n = a.size();
    if(n < 2) 
        return 0;

    vector<vector<int>> dp(k+1, vector<int>(n, 0));

    for(int i = 1; i <= k; i++) {
        int mini = a[0];
        for(int j = 1; j < n; j++) {
            mini = min(mini, a[j]-dp[i-1][j]);
            dp[i][j] = max(dp[i][j-1], a[j] - mini);
        }
    }
    return dp[k][n-1];
}
*/



/**
 * Time Complexity: O(N*N*K)
 * Space Complexity: O(N*K)
 */ 

/*
int maximumProfit(vector<int>& a, int k) {
    int n = a.size();
    if(n < 2) 
        return 0;

    vector<vector<int>> dp(k+1, vector<int>(n, 0));

    for(int i = 1; i <= k; i++) {
        for(int j = 1; j < n; j++) {
            int mini=a[0];
            for(int x = 1; x <= j; x++)
                mini = min(mini, a[x]-dp[i-1][x]);
            dp[i][j] = max(dp[i][j-1], a[j] - mini);
        }
    }

    return dp[k][n-1];
}
*/

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << maximumProfit(a, 2);
}

/*
8
3 3 5 0 0 3 1 4
*/