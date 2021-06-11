/*
    Time Complexity: O(V+E)
    Space Complexity: O(V+E)
*/

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    vector<Node*> neighbours;
};

Node* dfs(Node* node, unordered_map<Node*, Node*> mp) {
    if(mp.find(node) != mp.end()) 
        return mp[node];
    Node* copy = new Node();
    copy->val = node->val;
    mp[node] = copy;

    for(auto ele : node->neighbours) {
        (copy->neighbours).push_back(dfs(ele, mp));
    }
    return copy;
}

Node* cloneGraph(Node* node) {
    if(node == NULL)
        return NULL;
    unordered_map<Node*, Node*> mp;
    return dfs(node, mp);
}

Node* buildGraph() {
    Node* node1 = new Node();
    node1->val = 1;

    Node* node2 = new Node();
    node2->val = 2;
    
    Node* node3 = new Node();
    node3->val = 3;
    
    Node* node4 = new Node();
    node4->val = 4;
    
    vector<Node*> v;

    v.push_back(node2);
    v.push_back(node4);
    node1->neighbours = v;
    
    v.clear();
    
    v.push_back(node1);
    v.push_back(node3);
    node2->neighbours = v;
    
    v.clear();
    
    v.push_back(node2);
    v.push_back(node4);
    node3->neighbours = v;
    
    v.clear();
    
    v.push_back(node3);
    v.push_back(node1);
    node4->neighbours = v;
    
    return node1;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    Node* src = buildGraph();
    Node* src_cpy = cloneGraph(src);
}

/*
4 4
1 2
2 3
3 4
1 4
*/