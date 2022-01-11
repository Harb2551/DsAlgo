/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void solve(TreeNode <int> *root,TreeNode<int>* &prev){
    if(root==NULL)
        return;
    solve(root->left,prev);
    prev->left = NULL;
    prev->right = root;
    prev = root;
    solve(root->right,prev);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    TreeNode <int>* dum = new TreeNode<int>(-1);
    TreeNode <int>* prev = dum;
    solve(root,prev);
    prev->left = NULL;
    prev->right = NULL;
    return dum->right;
}












