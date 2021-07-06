/*
    Time Complexity: O(N)
    Space Complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Order of elements maintained
 * Temporary positive and negative array
 * Time Complexity: O(N); Space Complexity: O(N)
 */ 
void rearrange_A(vector<int>& a) {
    int n = a.size();

    vector<int> pos, neg;
    for(int i = 0; i < n; i++) {
        if(a[i] >= 0) {
            pos.push_back(a[i]);
        } else {
            neg.push_back(a[i]);
        }
    }

    int n1 = pos.size(), n2 = neg.size(), x = 0, y = 0, z = 0;
    while(x < n1 && y < n2) {
        if(z%2 == 0) {
            a[z] = pos[x];
            z += 1;
            x += 1;
        } else {
            a[z] = neg[y];
            z += 1;
            y += 1;
        }
    }

    while(x < n1) {
        a[z] = pos[x];
        z += 1;
        x += 1;
    }

    while(y < n2) {
        a[z] = neg[y];
        z += 1;
        y += 1;
    }
}

/**
 * Order of elements maintained
 * 
 * Time Complexity: O(N*N); Space Complexity: O(1)
 */ 

void rightrotate(vector<int>& a, int n, int outofplace, int cur)
{
    int tmp = a[cur];
    for (int i = cur; i > outofplace; i--)
        a[i] = a[i - 1];
    a[outofplace] = tmp;
}

void rearrange_B(vector<int>& a) {
    int n = a.size(), outofplace = -1;
 
    for(int i = 0; i < n; i++) {
        if(outofplace >= 0) {
            if((a[i] >= 0 && a[outofplace < 0]) || (a[i] < 0 && a[outofplace] >= 0)) {
                rightrotate(a, n, outofplace, i);
 
                if(i - outofplace >= 2)
                    outofplace = outofplace + 2;
                else
                    outofplace = -1;
            }
        }
 
        // if no entry has been flagged out-of-place
        if(outofplace == -1) {
            if((a[i] >= 0 && i % 2 == 1) || (a[i] < 0 && i % 2 == 0))
                outofplace = i;
        }
    }
}

/**
 * Order of elements NOT maintained
 * 
 * Time Complexity: O(N); Space Complexity: O(1)
 */ 
void rearrange_C(vector<int>& a) {
    int n = a.size();
    int i = 0, j = n-1;

    while(i < j) {
        while(i < n && a[i] >= 0)       i += 1;
        while(j >= 0 && a[j] < 0)       j -= 1;
        if(i < j)   swap(a[i], a[j]);       
    }

    // i is the index of 1st negative element
    if(i == 0 || i == n-1)
        return;

    int k = 0;
    while(k < n && i < n) {
        swap(a[k], a[i]);
        k += 2;
        i += 1;
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

    rearrange_B(a);

    for(auto ele : a) {
        cout << ele << " ";
    }
}

/*
10
-5 -2 5 2 4 7 1 8 0 -8
*/