/*
    Time Complexity: O(N)
    Space Complexity: O(1)
*/

/*
    Without maintaining order: [A] Quick Sort Approach; [B] Two Pointer Approach
    With maintaining order [C] Using extra space
*/

#include <bits/stdc++.h>
using namespace std;

void rearrange_A(vector<int>& a) {
    int n = a.size();
    int i = 0;

    for(int j = 0; j < n; j++) {
        if(a[j] < 0) {
            swap(a[i], a[j]);
            i += 1;
        }
    }
}

void rearrange_B(vector<int>& a) {
    int l = 0, r = a.size()-1;
    int cnt = 0;
    while(l <= r) {
        cnt += 1;
        if(a[l] < 0) {
            l += 1;
        } else {
            swap(a[l], a[r]);
            r -= 1;
        }
    }

    cout << cnt << endl;
}

void rearrange_C(vector<int>& a) {
    int n = a.size();

    int pos = 0;

    vector<int> b(a);
    for(int i = 0; i < n; i++) {
        if(b[i] < 0) {
            a[pos] = b[i];
            pos += 1;
        }
    }

    for(int i = 0; i < n; i++) {
        if(b[i] > 0) {
            a[pos] = b[i];
            pos += 1;
        }
    }
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

    rearrange_C(a);

    for(auto ele : a) {
        cout << ele << " ";
    }
}

/*
9
-12 11 -13 -5 6 -7 5 -3 -6
*/