/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map <int,int> mp1,mp2;
    int find_index(vector <int> v,int i,int j){
        int ans = INT_MAX;
        for(auto k=i;k<=j;k++){
            ans = min(ans,mp1[v[k]]);
        }
        return ans;
    }
    
    TreeNode* solve(vector <int> inorder,vector<int> preorder,int i,int j,int n){
        if(j<i)
            return NULL;
        int p = find_index(inorder,i,j);
        TreeNode *root = new TreeNode(preorder[p]);
        int ini = mp2[preorder[p]];
        root->left = solve(inorder,preorder,i,ini-1,n);
        root->right = solve(inorder,preorder,ini+1,j,n);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector <int> inorder = preorder;
        sort(inorder.begin(),inorder.end());
        mp1.clear();
        mp2.clear();
        int n = preorder.size();
        for(auto i=0;i<n;i++){
            mp1[preorder[i]] = i;
            mp2[inorder[i]] = i;
        }
        return solve(inorder,preorder,0,n-1,n);
    }
};