/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include <bits/stdc++.h> 
using namespace std;

int ans;

int solve(TreeNode<int> *root){
    if(root->left==NULL and root->right==NULL){
        ans = max(ans,root->data);
        return root->data;
    }
    int l=0,r=0;
    if(root->left)
        l = solve(root->left);
    if(root->right)
        r = solve(root->right);
    int temp = l+r+root->data;
    ans = max(temp,ans);
    return temp;
}

int largestSubtreeSum(TreeNode<int> *root) {
	// Write your code here.
    ans = INT_MIN;
    int temp = solve(root);
    return ans;
}







