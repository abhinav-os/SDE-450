/*
    Time Complexity: O(N)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

void threeWayPartition(vector<int>& a, int x, int y) {
    int n = a.size();
    int low = 0, mid = 0, high = n-1;
    while(mid <= high) {
        if(a[mid] < x) {
            swap(a[low], a[mid]);
            low += 1;
            mid += 1;
        } else if(a[mid] >= x && a[mid] <= y) {
            mid += 1;
        } else {
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

    int x, y;
    cin >> x >> y;

    threeWayPartition(a, x, y);
    for(auto ele : a) {
        cout << ele << " ";
    }
}

/*
5
1 2 3 3 4
1 2
*/