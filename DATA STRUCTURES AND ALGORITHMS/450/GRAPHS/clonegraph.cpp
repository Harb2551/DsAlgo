/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    vector <int> visited;
    vector <Node*> ans;
    
    Node* cloneGraph1(Node* node){
        vector <Node*> v;
        Node *temp = new Node(node->val);
        temp->neighbors = v;
        temp->val = node->val;
        ans[node->val] = temp;       
        int n = (node->neighbors).size();
        visited[node->val] = 1;
        for(auto i=0;i<n;i++){
            if(visited[node->neighbors[i]->val])
                v.push_back(ans[node->neighbors[i]->val]);
            else{
                Node* cur = cloneGraph1(node->neighbors[i]);
                v.push_back(cur);
            }
        }
        temp->neighbors = v;
        return temp;
    }
    
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        visited.resize(102,0);
        ans.resize(102);
        return cloneGraph1(node);
    }
};




