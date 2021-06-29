/*
    Time Complexity: O(N); Given approach takes atmost of O(3*(n-1)/2) if n is odd, and O(3*(n-2)/2 + 1) if n is even.
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

struct MinMax{
    int min;
    int max;

    MinMax(int _min, int _max) {
        min = _min;
        max = _max;
    }

    MinMax() {

    }
};

MinMax minAndMax(vector<int> a) {
    MinMax ans;

    /*
    ans.min = *min_element(a.begin(), a.end());
    ans.max = *max_element(a.begin(), a.end());
    */

    int n = a.size();

    int itr;

    if(n&1) {
        ans.min = a[0];
        ans.max = a[0];
        itr = 1;
    } else {
        ans.min = min(a[0], a[1]);
        ans.max = min(a[0], a[1]);
        itr = 2;
    }

    while(itr < n-1) {
        if(a[itr] > a[itr+1]) {
            ans.max = max(ans.max, a[itr]);
            ans.min = min(ans.min, a[itr+1]);
        } else {
            ans.max = max(ans.max, a[itr+1]);
            ans.min = min(ans.min, a[itr]);
        }

        itr += 2;
    }

    return ans;
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

    auto ans = minAndMax(a);
    cout << ans.min << " " << ans.max;
}

/*
6
1000 11 445 1 330 3000
*/