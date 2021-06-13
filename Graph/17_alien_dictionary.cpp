/*
    Time Complexity: o(N+K)
    Space Complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

string topo_sort(vector<vector<int>>& adj, int n) {
    vector<int> indegree(n, 0);
    for(int i = 0; i < n; i++) {
        for(auto ele:adj[i]) {
            indegree[ele] += 1;
        }
    }

    string ans = "";
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        char ch = cur + 'a';
        ans += ch;

        for(auto ele:adj[cur]) {
            indegree[ele] -= 1;
            if(indegree[ele] == 0) {
                q.push(ele);
            }
        }
    }

    return ans;
}

string findOrder(vector<string>& str, int n, int k) {
    vector<vector<int>> adj(k, vector<int>());
    for(int i = 1; i < n; i++) {
        string str1 = str[i-1];
        string str2 = str[i];

        int len1 = str1.length();
        int len2 = str2.length();

        for(int j = 0; j < min(len1, len2); j++) {
            if(str1[j] != str2[j]) {
                int u = str1[j] - 'a';
                int v = str2[j] - 'a';

                adj[u].push_back(v);
                break;
            }
        }
    }

    return topo_sort(adj, k);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, k;
    cin >> n >> k;

    vector<string> str(n);
    for(int i = 0; i < n; i++)  {
        cin >> str[i];
    }

    string ans = findOrder(str, n ,k);
    cout << ans;
}

/*
5 4     // Numner of words, Number of letters in dictionary
baa
abcd
abca
cab
cad
*/