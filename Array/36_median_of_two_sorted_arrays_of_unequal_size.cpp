/*
    Time Complexity: O(log(min(n, m))
    Space Complexity: O(1)
*/

// Works for both equal and unequal size

#include <bits/stdc++.h>
using namespace std;

double median(vector<int>& a, vector<int>& b) {
    int n = a.size(), m = b.size();

    if(m < n) {
        return median(b, a);
    }

    int low = 0, high = n;
    while(low <= high) {
        int mid = (low + high)/2;
        int cut1 = mid;
        int cut2 = (n+m+1)/2 - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : a[cut1-1];
        int l2 = (cut2 == 0) ? INT_MIN : b[cut2-1];
        int r1 = (cut1 == n) ? INT_MAX : a[cut1];
        int r2 = (cut2 == m) ? INT_MAX : b[cut2];

        if(l1 <= r2 && l2 <= r1) {
            double ans;
            if((n+m)%2 == 0)
                ans = (1.0 * (max(l1, l2) + min(r1, r2)))/2;
            else
                ans = max(l1, l2);

            return ans;
        } else if(l1 > r2) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return 0.0;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++)      cin >> a[i];
    for(int i = 0; i < m; i++)      cin >> b[i];
    
    cout << median(a, b);
}

/*
4 6
7 12 14 15
1 2 3 4 9 11
*/