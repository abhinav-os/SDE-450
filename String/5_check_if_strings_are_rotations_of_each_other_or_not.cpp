/*
    Time Complexity: theta(N1 + N2)
    Space Complexity: O(N1 + N2)
*/

#include <bits/stdc++.h>
using namespace std;

bool areRotations(string s1, string s2) {
    if(s1.length() != s2.length())  {
        return false;
    }

    string temp = s1 + s2;
    if(temp.find(s2) != string::npos)
        return true;
    return false;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    string s1, s2;
    cin >> s1 >> s2;
    if(areRotations(s1, s2)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}

/*
geeksforgeeks
forgeeksgeeks
*/