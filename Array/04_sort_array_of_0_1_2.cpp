/*
    Time Complexity: O(N); Only 1 pass.
    Space Complexity: O(1)
*/

/*
a[1 ... low-1] --> 0
a[low ... mid-1] --> 1
a[mid ... high] ---> Unknown
a[high+1 ... N] ---> 2
*/

#include <bits/stdc++.h>
using namespace std;

void sort012(vector<int>& a) {
    int n = a.size();
    int low = 0, mid = 0, high = n-1;
    while(mid <= high) {
        if(a[mid] == 0) {
            swap(a[low], a[mid]);
            low += 1;
            mid += 1;
        } else if(a[mid] == 1) {
            mid += 1;
        } else if(a[mid] == 2) {
            swap(a[mid], a[high]);
            high -= 1;
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

    sort012(a);

    for(auto ele : a) {
        cout << ele << " ";
    }
}

/*
5
0 2 1 2 0
*/