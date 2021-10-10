/*
    Time Complexity: O(N * SUM)
    Space Complexity: O(N * SUM)
*/

/*
    Variation of 0/1 Knapsack
*/

#include <bits/stdc++.h>
using namespace std;

bool equalPartition(vector<int>& a)
{
    int n = a.size();
    int sum = 0;
    for(int i = 0; i < n; i++) 
        sum += a[i];

    if(sum % 2 == 1)
        return false;

    sum /= 2;

    vector<vector<bool>> dp(n+1, vector<bool>(sum+1));
    
    for(int i = 0; i <= sum; i++)       dp[0][i] = false;
    for(int i = 0; i <= n; i++)         dp[i][0] = true;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= sum; j++) {
            if(a[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j - a[i-1]] or dp[i-1][j];
        }
    }

    return dp[n][sum];
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i];

    if(equalPartition(a))
        cout << "YES";
    else
        cout << "NO";
}

/*
4
1 5 11 5
*/