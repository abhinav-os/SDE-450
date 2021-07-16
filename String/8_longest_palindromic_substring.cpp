/*
    Time Complexity: O(N*N)
    Space Complexity: O(1)
*/

/**
 * For every index assume it as the centre of substring and check if we can make a palindrome or not by moving left & right.
 */ 

#include <bits/stdc++.h>
using namespace std;

string longestPalin(string s) {
    int n = s.length();
    int start=0, len=1;

    for(int i = 1; i < n; i++) {
        // Even length with centre i-1, i
        int cur_len = 0, low = i-1, high = i;
        while(low >= 0 && high < n && s[low] == s[high]) {
            // cout << low << " " << high << "\n"; 
            cur_len += 2;
            if(cur_len > len) {
                len = cur_len;
                start = low;
            }

            low -= 1;
            high += 1;
        }

        // Even length with centre i     
        cur_len = 1, low = i-1, high = i+1;
        while(low >= 0 && high < n && s[low] == s[high]) {
            cur_len += 2;
            if(cur_len > len) {
                len = cur_len;
                start = low;
            }

            low -= 1;
            high += 1;
        }
    }
    
    return s.substr(start, len);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    string s;
    cin >> s;
    cout << longestPalin(s);
}

/*
aaaabbaa
*/