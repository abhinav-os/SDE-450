/*
    Time Complexity: O(N)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

/*
https://www.youtube.com/watch?v=32Ll35mhWg0
Slow pointer and fast pointer approach as of linked list cycle.
*/

int findDuplicate(vector<int> a) {
    int n = a.size();

    int slow = a[0];
    int fast = a[0];

    do {
        slow = a[slow];
        fast = a[a[fast]];
    } while(fast != slow);

    fast = a[0];
    while(fast != slow) {
        fast = a[fast];
        slow = a[slow];
    }

    return slow;
}

/*
Time: O(N*logN)
Space: O(1)

Binary Search: Numbers in range [1, N]; low = 1, high = N, get mid. Check count of numbers less than or equal to mid in the array. If it is less than or equal to mid, then obviously repeating element is in the range [mid+1, high], else it is in [low, mid].

Doesn't change relative ordering of elements.
*/

/*
int findDuplicate(vector<int> a) {
    int n = a.size();
    int low=1, high=n-1;

    while(low < high) {
        int mid = (low + high)/2;
        int count = 0;

        for(int i = 0; i < n; i++) {
            if(a[i] <= mid) {
                count += 1;
            }
        }

        if(count <= mid) {
            low = mid+1;
        } else {
            high = mid;
        }
    }

    return low;
}
*/


/*
Time: O(N*logN)
Space: O(N*logN)

Simple Sorting.
Changes ordering of elements.
*/

/*
int findDuplicate(vector<int> a) {
    int n = a.size();

    sort(a.begin(), a.end());
    for(int i = 1; i < n; i++) {
        if(a[i] == a[i-1]) {
            return a[i];
        }
    }
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

    cout << findDuplicate(a);
}

/*

*/