/*
    Time Complexity: O(N)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int buy = INT_MAX, profit=0;
    for(int i = 0; i < n; i++) {
        buy = min(prices[i], buy);
        profit = max(profit, prices[i]-buy);
    }

    return profit;
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
    cout << maxProfit(a);
}

/*
6
7 1 5 3 6 4
*/