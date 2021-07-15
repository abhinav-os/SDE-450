/*
    Time Complexity: O(N)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string& str) {
    int n = str.length();
    for(int i = 0; i < n/2; i++) {
        if(str[i] != str[n-i-1])
            return false;
    }
    return true;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    string s;
    cin >> s;
    if(isPalindrome(s)) {
        cout << "Palindrome";
    } else {
        cout << "Not Palindrome";
    }
}

/*
abba
*/