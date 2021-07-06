/*
    Time Complexity: O(N*N)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX 10

void multiply(vector<int>& a, int n) {
    int carry = 0;
    for(int i = 0; i < MAX; i++) {
        int cur = a[i] * n + carry;
        a[i] = cur % 10;
        carry = cur / 10;
    }
}

vector<int> factorial(int n) {
    vector<int> ans_rev(MAX, 0);
    ans_rev[0] = 1;

    for(int i = 2; i <= n; i++) {
        multiply(ans_rev, i);
    }

    reverse(ans_rev.begin(), ans_rev.end());

    vector<int> ans;
    int j = 0;
    while(ans_rev[j] == 0) {
        j += 1;
    }
    for(; j < MAX; j++) {
        ans.push_back(ans_rev[j]);
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
    vector<int> ans = factorial(n);
    for(auto ele : ans) {
        cout << ele;
    }
}

/*
10
*/