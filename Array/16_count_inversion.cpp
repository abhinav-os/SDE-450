/*
    Time Complexity: O(N*logN)
    Space Complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& a, int left, int mid, int right, int& ans) {
    // [left,..,mid] [mid+1,...,right]
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> temp1(n1);
    vector<int> temp2(n2);

    int i, j, k;

    for(i = 0; i < n1; i++) {
        temp1[i] = a[i + left];
    }

    for(i = 0; i < n2; i++) {
        temp2[i] = a[i + mid + 1];
    }
    
    i = 0, j = 0, k = left;

    while(i < n1 && j < n2) {
        if(temp1[i] <= temp2[j]) {
            a[k++] = temp1[i++];
        } else {
            a[k++] = temp2[j++]; 
            ans += (n1-i);
        }
    }

    while(i < n1) {
        a[k++] = temp1[i++];
    }

    while(j < n2) {
        a[k++] = temp2[j++];
    }
}

void mergeSortUtil(vector<int>& a, int left, int right, int& ans) {
    if(left < right) {
        int mid = (left + right) / 2;

        mergeSortUtil(a, left, mid, ans);
        mergeSortUtil(a, mid+1, right, ans);

        merge(a, left, mid, right, ans);
    }
}

int inversionCount(vector<int>& a) {
    int left = 0, right = a.size() - 1;
    int ans = 0;

    mergeSortUtil(a, left, right, ans);

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

    cout << inversionCount(a) << "\n";

    /*
    for(auto ele : a) {
        cout << ele << " ";
    }
    */
}

/*
5
2 4 1 3 5
*/