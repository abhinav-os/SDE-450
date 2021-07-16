/*
    Time Complexity: O(2^N)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

string countAndSay(int n) {
    string ans = "1";
    for(int i = 2; i <= n; i++) {
        int cnt = 1;
        string cur = "";
        for(int j = 1; j < ans.length(); j++) {
            if(ans[j] != ans[j-1]) {
                cur += (to_string(cnt) + ans[j-1]);
                cnt = 1;
            } else {
                cnt += 1;
            }
        }

        cur += (to_string(cnt) + ans.back());
        ans = cur;
    }

    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    cout << countAndSay(n);
}

/*
4
*/