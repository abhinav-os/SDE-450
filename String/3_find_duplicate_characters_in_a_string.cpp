/*
    Time Complexity: O(N)
    Space Complexity: O(K); K: Alphabet Size
*/

#include <bits/stdc++.h>
using namespace std;

string duplicates(string str) {
    unordered_map<char, int> mp;
    int n = str.length();

    for(int i = 0; i < n; i++)
        mp[str[i]] += 1;

    string ans = "";
    for(auto itr = mp.begin(); itr != mp.end(); itr++) {
        if(itr->second > 1) 
            ans += (itr->first);
    }   

    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    string s;
    cin >> s;
    string ans = duplicates(s);
    for(auto ele : ans) {
        cout << ele << " ";
    }
}

/*
geeksforgeeks
*/