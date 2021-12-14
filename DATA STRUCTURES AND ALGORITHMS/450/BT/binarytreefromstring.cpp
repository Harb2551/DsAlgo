/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

#include <bits/stdc++.h>
using namespace std;

BinaryTreeNode<int>* preorder(BinaryTreeNode<int>* root){
    
    if(root==NULL or root->data==-1)
        return NULL;
    root->left = preorder(root->left);
    root->right = preorder(root->right);
    return root;
}

BinaryTreeNode<int>* treeFromBracket(string &str)
{
    // Write your code here
    stack <BinaryTreeNode<int>*> s;
    int n = str.length();
    BinaryTreeNode<int>* ans = NULL;
    for(auto i=0;i<n;i++){
        if(str[i]>='0' and str[i]<='9'){
            int temp=0;
            while(str[i]>='0' and str[i]<='9'){
                temp += temp*10 + str[i]-'0';
                i++;
            }
            BinaryTreeNode<int> *cur = new BinaryTreeNode<int>(temp);            
            if(!s.empty()){
                if(s.top()->left==NULL){
                    s.top()->left = cur;
                }
                else if(s.top()->right==NULL)
                    s.top()->right = cur;
                s.push(cur);
            }
            else{
                ans = cur;
                s.push(cur);
            }
            i--;
        }        
        if(str[i]==')')
            s.pop();
        if(str[i]=='(' and str[i+1]==')'){
            s.top()->left = new BinaryTreeNode<int>(-1);
            i++;
        }
    }
    ans = preorder(ans);
    return ans;
}







