/*
    Time Complexity: O(N*N)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

bool find3Numbers(vector<int>& a, int x) {
    int n = a.size();
    if(n < 3) {
        return false;
    }

    sort(a.begin(), a.end());

    for(int i = 0; i < n-2; i++) {
        int temp = x-a[i];
        int left = i+1, right = n-1;

        while(left < right) {
            int sum = a[left] + a[right];
            if(sum == temp) {
                return true;
            } else if(sum < temp) {
                left += 1;
            } else {
                right -= 1;
            }
        }
    }

    return false;
}

/**
 * Time Complexity: O(N*N)
 * Space Complexity: O(N)
 */ 

/*
bool find3Numbers(vector<int>& a, int x) {
    int n = a.size();
    if(n < 3) {
        return false;
    }

    for(int i = 0; i < n-2; i++) {
        int temp = x - a[i];
        unordered_set<int> s;
        s.insert(a[i+1]);
        for(int j = i+2; j < n; j++) {
            if(s.find(temp - a[j]) != s.end()) {
                return true;
            }

            s.insert(a[j]);
        }
    }

    return false;
}
*/

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if(find3Numbers(a, k)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}

/*
6 13
1 4 45 6 10 8
*/