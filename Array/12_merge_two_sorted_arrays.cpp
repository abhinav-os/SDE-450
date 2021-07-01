/*
    Time Complexity: O((N+M)log(N+M))
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time: O(N+M); Space: O(N+M)             
Basic Sorting
*/
void merge_A(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int m = b.size();

    vector<int> c;

    int i = 0, j = 0;
    while(i < n && j < m) {
        if(a[i] > b[j]) {
            c.push_back(b[j]);
            j += 1;
        } else {
            c.push_back(a[i]);
            i += 1;
        }
    }

    while(i < n) {
        c.push_back(a[i]);
        i += 1;
    } 

    while(j < m) {
        c.push_back(b[j]);
        j += 1;
    }
    
    i = 0;

    while(i < n) {
        a[i] = c[i];
        i += 1;
    }

    j = 0;
    while(j < m) {
        b[j] = c[i];
        j += 1;
        i += 1;
    }
}



/*
Time: O(N*M); Space: O(1)               
Inserting in the Sorted Array b
*/
void merge_B(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int m = b.size();

    int i,j;

    for(j = m-1; j >= 0; j--) {
        int last = a.back();
        for(i = n-2; i >= 0 && a[i] > b[j]; i--) {
            a[i+1] = a[i];
        }

        // If any element of a is moved or i != n-2
        if(i != n-2 || last > b[j]) {
            a[i+1] = b[j];
            b[j] = last;
        }
    }
}


/*
Time: O((N+M)log(N+M)); Space: O(1)     
Gap Method
*/
int nextGap(int n) {
    if(n <= 1) {
        return 0;
    }

    return (n/2) + (n%2);
}
void merge_C(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int m = b.size();

    int i, j, gap = n + m;

    for(gap = nextGap(gap); gap > 0; gap = nextGap(gap)) {
        for(i = 0; i + gap < n; i++) {
            if(a[i] > a[i+gap]) {
                swap(a[i], a[i+gap]);
            }
        }

        for(j = gap > n ? gap-n : 0; i < n && j < m; i++, j++) {
            if(a[i] > b[j]) {
                swap(a[i], b[j]);
            }
        }

        if(j < m) {
            for(j = 0; j+gap < m; j++) {
                if(b[j] > b[j+gap]) {
                    swap(b[j], b[j+gap]);
                }
            }
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int j = 0; j < m; j++) {
        cin >> b[j];
    }

    merge_C(a, b);

    for(auto ele : a) {
        cout << ele << " ";
    }
    cout << "\n";
    for(auto ele : b) {
        cout << ele << " ";
    }
}

/*
4 5
1 3 5 7
0 2 6 8 9
*/