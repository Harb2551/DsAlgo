/*************************************************************
    
    Following is the Binary Tree node structure.
    
    class BinaryTreeNode {
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
vector <vector<int>> ans;
vector <int> temp;

void solve(BinaryTreeNode<int> *root,int k){
    temp.push_back(root->data);
    if(root->left)
        solve(root->left,k);
    if(root->right)
        solve(root->right,k);
    int n = temp.size();
    int sum=0;
    for(auto i=n-1;i>=0;i--){
        sum += temp[i];
        if(sum==k){
            vector <int> cur;
            for(auto j=i;j<n;j++)
                cur.push_back(temp[j]);
            ans.push_back(cur);
        }
    }
    temp.pop_back();
}

vector<vector<int>> kPathSum(BinaryTreeNode<int> *root, int k) {
    // Write your code here.
    temp.clear();
    ans.clear();
    solve(root,k);
    return ans;
}














