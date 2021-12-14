/**********************************************************
    Following is the Binary Tree Node class structure

    template <typename T>
    class TreeNode {
    public :
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/
#include <bits/stdc++.h>
using namespace std;

bool anagram(TreeNode<int>*root1, int n, TreeNode<int>*root2, int m)
{
	// Write your code here
    queue <TreeNode<int>*> q1;
    queue <TreeNode<int>*> q2;
    q1.push(root1);
    q2.push(root2);
    if(q1.front()->val!=q2.front()->val)
        return false;
    while(!q1.empty() and !q2.empty()){
        int n = q1.size();
        map <int,int> mp1;
        for(auto i=0;i<n;i++){
            auto cur = q1.front();
            q1.pop();
            if(cur->left){
                q1.push(cur->left);
                mp1[cur->left->val]++;
            }
            if(cur->right){
                q1.push(cur->right);
                mp1[cur->right->val]++;
            }
        }
        int m = q2.size();
        map <int,int> mp2;
        for(auto i=0;i<m;i++){
            auto cur = q2.front();
            q2.pop();
            if(cur->left){
                q2.push(cur->left);
                mp2[cur->left->val]++;
            }
            if(cur->right){
                q2.push(cur->right);
                mp2[cur->right->val]++;
            }
        }
        if(mp1.size()!=mp2.size())
            return false;
        for(auto i=mp1.begin();i!=mp1.end();i++){
            if(mp2[i->first]!=i->second)
                return false;
        }
    }
    return true;
}










