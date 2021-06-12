/*
    Time Complexity: O(V+E)
    Space Complexity: O(V+E) + O(V)
*/

#include <bits/stdc++.h>
using namespace std;

int find_difference(string a, string b) {
    int cnt = 0;
    int n = a.length();

    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            cnt += 1;
        }
    }

    return cnt;
}

int bfs(vector<vector<int> > adj, int src, int dest) {
    int n = adj.size();
    vector<bool> vis(n, false);

    queue<pair<int, int> > q;
    q.push({src, 1});

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        vis[cur.first] = true;
        if(cur.first == dest)
            return cur.second;

        for(int j = 0; j < adj[cur.first].size(); j++) {
            int ele = adj[cur.first][j];

            if(!vis[ele]) {
                q.push({ele, cur.second + 1});
            }
        }
    }

    return 0;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int src, dest, nodes;
    if(find(wordList.begin(), wordList.end(), beginWord) != wordList.end()) {
        src = find(wordList.begin(), wordList.end(), beginWord) - wordList.begin();
        nodes = wordList.size();
    } else {
        wordList.push_back(beginWord);
        nodes = wordList.size();
        src = nodes - 1;
    }

    if(find(wordList.begin(), wordList.end(), endWord) != wordList.end()) {
        dest = find(wordList.begin(), wordList.end(), endWord) - wordList.begin();
    } else {
        return 0;
    }
    
    // Construct adjacency list
    vector<vector<int> > adj(nodes, vector<int>());
    for(int i = 0; i < nodes; i++) {
        for(int j = i+1; j < nodes; j++) {
            int diff = find_difference(wordList[i], wordList[j]);
            if(diff == 1) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    return bfs(adj, src, dest);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    string beginWord, endWord;
    cin >> beginWord >> endWord;

    int n;
    cin >> n;
    vector<string> wordList;
    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        wordList.push_back(temp);
    }

    int ans = ladderLength(beginWord, endWord, wordList);
    cout << ans;
}

/*
hit cog
6
hot
dot
dog
lot
log
cog
*/