/*
    Time Complexity: O(N)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int sb(vector<int>& a, int x) {
    int n = a.size(), left = 0, right = 0, ans = n+1, sum = 0;
    while(right < n) {
        while(right < n && sum <= x) {
            sum += a[right];
            right += 1;
        }
            
        while(left < n && sum > x) {
            ans = min(ans, right - left);
            sum -= a[left];
            left += 1;
        }
    }
    return ans;
}

// Not so nice implementation
/*
int sb(vector<int>& a, int x) {
    int n = a.size(), left = 0, right = -1, ans = 0, sum = 0;
    while(sum <= x) {
        right += 1;
        sum += a[right]; 
    }

    ans = right-left+1;

    while(right < n && left < right) {
        while(sum - a[left] > x && left < right) {
            sum -= a[left];
            left += 1;
            ans = min(ans, right-left+1);
        } 

        sum -= a[left];
        left += 1;
        
        while(sum + a[right+1] <= x && right+1 < n) {
            right += 1;
            sum += a[right];
        }
        
        right += 1;
        sum += a[right];
    }

    return ans;
}
*/

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << sb(a, x);
}

/*
6 51
1 4 45 6 0 19
*/