/*
    Time Complexity: O(N * M * log N)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

struct Element{
    int val;
    int row;
    int col;

    Element(int val, int row, int col) : val(val), row(row), col(col) {}
};
 
struct CompareElement{
    bool operator()(Element const& e1, Element const& e2) {
        return e1.val > e2.val;
    }
};

void print(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();

    priority_queue<Element, vector<Element>, CompareElement> pq;

    for(int i = 0; i < n; i++) {
        pq.push(Element(mat[i][0], i, 0));
    }

    while(!pq.empty()) {
        Element e = pq.top();
        pq.pop();
        cout << e.val << " ";
        if(e.col != m-1)
            pq.push(Element(mat[e.row][e.col + 1], e.row, e.col + 1));
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    print(mat);
}

/*
4 4
10 20 30 40
15 25 35 45
27 29 37 48
32 33 39 50
*/