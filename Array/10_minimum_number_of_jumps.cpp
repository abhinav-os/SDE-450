/*
    Time Complexity: O(N)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * maxReach: At all times contains maximum reachable index, initialized to a[0];
 * jumps: Amount of jump required to reach that maximum reachabale index, initialized to 1;
 * steps: Maximum step we can still take,  initialized to a[0]
 * 
 * Iterate from index 1: Check if we reached end of the array, if yes, return jumps
 * Else, update maxReach := max(maxReach, i + a[i]); steps := steps - 1
 * Check if steps is 0: If yes, we need another jump (jumps := jumps + 1); Update steps
 */ 

int minJumps(vector<int> a) {
    int n = a.size();
    
    if(n == 1) {
        return 0;
    }

    if(a[0] == 0) {
        return -1;
    }

    int maxReach = a[0], jumps = 1, steps = a[0];
    for(int i = 1; i < n; i++) {
        if(i == n-1) {
            return jumps;
        }

        maxReach = max(maxReach, i + a[i]);
        steps -= 1;

        if(steps == 0) {
            jumps += 1;
            if(i >= maxReach) {
                return -1;
            }
            steps = maxReach - i;
        }
    }
}

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