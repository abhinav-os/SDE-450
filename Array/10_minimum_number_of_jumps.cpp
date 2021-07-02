/*
    Time Complexity: 
    Space Complexity: 
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * DP Approach
 * Time Complexity: O(N*N)
 * Space Complexity: O(N)
 */

/*
int minJumps(vector<int> a) {
    int n = a.size();

    if(a[0] == 0) {
        return -1;
    }
    if(n == 1) {
        return 0;
    }

    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(j + a[j] >= i && dp[j] != INT_MAX) {
                dp[i] = min(dp[i], dp[j] + 1);
                break;
            }
        }
    }

    return (dp[n-1] == INT_MAX ? -1 : dp[n-1]);
}
*/

int minJumps(vector<int> a) {
    int n = a.size();
    
}

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

    cout << minJumps(a);
}

/*
11
1 3 5 8 9 2 6 7 6 8 9
*/