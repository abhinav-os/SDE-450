/*
    Time Complexity: Worst case complexity of O(N*N); Average takes O(N)
    Space Complexity: O(1)
*/

/*
ASSUMPTION: ALL ELEMENTS ARE DISTINCT.
Modified Quick Sort to Quick Select. Pick a pivot, place it at correct position, if it's kth position, return. Else recur for ONLY ONE side.
*/

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& a, int l, int r) {
    int x = a[r], i = l;

    for(int j = l; j < r; j++) {
        if(a[j] <= x) {
            swap(a[i], a[j]);
            i += 1;
        }
    }
    swap(a[i], a[r]);
    return i;
}

int randomPartition(vector<int>& a, int l, int r) {
    int n = r-l+1;
    int pivot = rand() % n;
    swap(a[l+pivot], a[r]);
    return partition(a, l, r);
}

int kthSmallest(vector<int>& a, int l, int r, int k) {
    if(k > 0 && r-l+1 >= k) {
        // Randomly partition the array around a pivot element and get its position.
        int pos = randomPartition(a, l, r);

        if(pos-l == k-1) {
            return a[pos];
        } else if(pos-l > k-1) {
            // Recurr for left subarray
            return kthSmallest(a, l, pos-1, k);
        } else {
            // Recurr for right subarray
            return kthSmallest(a, pos+1, r, k-pos-1+l);
        }
    }

    return INT_MAX;
}

pair<int, int> kthMinMax(vector<int>& a, int k) {
    int n = a.size();

    int min = kthSmallest(a, 0, n-1, k);
    int max = kthSmallest(a, 0, n-1, n-k+1);
    
    return {min, max};
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, k;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> k;

    pair<int, int> ans = kthMinMax(a, k);
    cout << ans.first << " " << ans.second;
}

/*
6
7 10 4 3 20 15
2
*/