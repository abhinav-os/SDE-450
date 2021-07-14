/*
    Time Complexity: O(K * log N)
    Space Complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

struct Element{
    int val;
    int row;
    int col;

    Element(int val, int row, int col) : val(val), row(row), col(col) {}
};

struct compareElement{
    bool operator()(Element const& e1, Element const& e2) {
        return e1.val > e2.val;
    }
};

int kthSmallest(vector<vector<int>>& mat, int k) {
    int n = mat.size();

    priority_queue<Element, vector<Element>, compareElement> pq;
    for(int i = 0; i < n; i++) {
        pq.push(Element(mat[i][0], i, 0));
    }

    for(int i = 0; i < k-1; i++) {
        Element e = pq.top();
        pq.pop();

        if(e.col != n-1)
            pq.push(Element(mat[e.row][e.col + 1], e.row, e.col + 1));
    }

    return pq.top().val;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, k;
    cin >> n >> k;
    vector<vector<int>> mat(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    cout << kthSmallest(mat, k);
}

/*
4 3
16 28 60 64
22 41 63 91
27 50 87 93
36 78 87 94
*/