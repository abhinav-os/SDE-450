/*
    Time Complexity: O(N*K)
    Space Complexity: O(K-1)
*/

/**
 * Number of majority elements can't be more than k-1.
 * Create a temporary array temp, to store k-1 majority elements and its count at all times
 * Traverse input array: If a[i] is already present in temp, increase its count by 1.
 *      Else if a[i] is not already present in temp, check if there is an empty sapce in temp
 *             If yes, store a[i] and mark its count as 1. If there is no empty space:
 *                      Decrease count by 1 of all k-1 elements.
 * 
 * Now, temp contains potential majority elements. Find actual count of those elements and check if it's more than n/k;
 */ 

#include <bits/stdc++.h>
using namespace std;

struct eleCount{
    int ele;
    int cnt;
};

vector<int> countOccurence(vector<int>& a, int k) {
    int n = a.size(), i, j, x, y;
    vector<int> ans;

    if(k < 2) {
        return ans;
    }
    
    vector<eleCount> temp(k-1);
    for(i = 0; i < k-1; i++) {
        temp[i].cnt = 0;
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < k-1; j++) {
            if(temp[j].ele == a[i]) {
                temp[j].cnt += 1;
                break;
            }
        }

        if(j == k-1) {
            for(x = 0; x < k-1; x++) {
                if(temp[x].cnt == 0) {
                    temp[x].ele = a[i];
                    temp[x].cnt = 1;
                    break;
                }
            }

            if(x == k-1) {
                for(y = 0; y < k-1; y++) {
                    temp[y].cnt -= 1;
                }
            }
        }
    }

    for(i = 0; i < k-1; i++) {
        int actual_count = 0;
        for(j = 0; j < n; j++) {
            if(a[j] == temp[i].ele) {
                actual_count += 1;
            }
        }

        if(actual_count > n/k) {
            ans.push_back(temp[i].ele);
        }
    }

    return ans;
}

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

    vector<int> ans = countOccurence(a, k);

    cout << ans.size() << "\n";
    for(auto ele : ans) {
        cout << ele << " ";
    }
}

/*
8 4
3 1 2 2 1 2 3 3
*/