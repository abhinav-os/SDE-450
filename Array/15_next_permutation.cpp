/*
    Time Complexity: O(N)
    Space Complexity: O(1)
*/
/**
 * Traverse from back upto idx1 such that a[idx1] < a[idx1 + 1]
 * Traverse from back upto idx2 such that a[idx2] > a[idx1]
 * Swap a[idx1], a[idx2]
 * Reverse a[idx1 + 1,...,N]
 */ 

#include <bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> a) {
    int idx1 = -1, n = a.size();

    for(int i = n-2; i >= 0; i--) {
        if(a[i] < a[i+1]) {
            idx1 = i;
            break;
        }
    }

    if(idx1 == -1) {
        reverse(a.begin(), a.end());
        return a;
    }

    int idx2;
    for(int i = n-1; i > idx1; i--) {
        if(a[i] > a[idx1]) {
            idx2 = i;
            break;
        }
    }

    swap(a[idx1], a[idx2]);
    reverse(a.begin()+idx1+1, a.end());
    return a;
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

    vector<int> ans = nextPermutation(a);
    for(int ele : ans) {
        cout << ele << " ";
    }
}

/*
3
2 1 3
*/