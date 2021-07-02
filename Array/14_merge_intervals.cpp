/*
    Time Complexity: O(N*logN)
    Space Complexity: O(N) ---> For storing the answer.
*/

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> merge(vector<pair<int, int>>& intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<pair<int, int>> ans;
    int start = intervals[0].first, end = intervals[0].second;

    for(int i = 1; i < n; i++) {
        if(intervals[i].first <= end) {
            end = max(end, intervals[i].second);
        } else {
            ans.push_back({start, end});
            start = intervals[i].first;
            end = intervals[i].second;
        }
    }

    ans.push_back({start, end});
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }    

    vector<pair<int, int>> ans = merge(v);
    for(auto ele : ans) {
        cout << ele.first << " " << ele.second << "\n";
    }
}

/*
4
1 3
2 6
8 10
15 18
*/