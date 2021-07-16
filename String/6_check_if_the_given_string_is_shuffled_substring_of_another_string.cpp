/*
    Time Complexity: O(26 * N2)
    Space Complexity: O(26)
*/

#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
    for(int i = 0; i < 26; i++) {
        if(a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

bool isShuffledSubstring(string s1, string s2) {
    int n1 = s1.length(), n2 = s2.length();
    if(n1 > n2) {
        return false;
    }

    vector<int> cnt1(26, 0), cnt2(26, 0);
    for(int i = 0; i < n1; i++) {
        cnt1[s1[i] - 'a'] += 1;
        cnt2[s2[i] - 'a'] += 1;
    }
        
    if(compare(cnt1, cnt2))
        return true;

    for(int i = n1; i < n2; i++) {
        cnt2[s2[i] - 'a'] += 1;
        cnt2[s2[i - n1] - 'a'] -= 1;

        if(compare(cnt1, cnt2))
            return true;
    }

    return false;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    string s1, s2;
    cin >> s1 >> s2;

    if(isShuffledSubstring(s1, s2)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}

/*
onetwofour
hellofourtwooneworld
*/