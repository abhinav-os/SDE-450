/*
    Time Complexity: O(N)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int trappingWater(vector<int>& a) {
    int n = a.size();

    int left_max = 0, right_max = 0, low = 0, high = n-1, ans = 0;
    while(low <= high) {
        if(a[low] < a[high]) {
            if(left_max < a[low]) {
                left_max = a[low];
            } else {
                ans += (left_max - a[low]);
            }

            low += 1;
        } else {
            if(right_max < a[high]) {
                right_max = a[high];
            } else {
                ans += (right_max - a[high]);
            }

            high -= 1;
        }
    }

    return ans;
}


/**
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

/* 
int trappingWater(vector<int>& a) {
    int n = a.size();
    vector<int> left(n), right(n);
    left[0] = a[0], right[n-1] = a[n-1];
    for(int i = 1; i < n; i++)      left[i] = max(left[i-1], a[i]);
    for(int i = n-2; i >= 0; i--)   right[i] = max(right[i+1], a[i]);

    int ans = 0;
    for(int i = 1; i < n-1; i++) {
        ans += max((min(left[i], right[i]) - a[i]), 0);
    }
    return ans;
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

    cout << trappingWater(a);
}

/*
6
3 0 0 2 0 4
*/