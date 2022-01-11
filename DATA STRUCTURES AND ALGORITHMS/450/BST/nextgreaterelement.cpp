struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node *root,int key, Node* &succ){
   if(root==NULL)
       return new Node(key);
   if(root->data>key){
       succ = root;
       root->left = insert(root->left,key,succ);
   }
   else{
       root->right = insert(root->right,key,succ);
   }
   return root;
}

vector<int> leastGreaterElement(vector<int> &arr) 
{
    //    Write your code here
	int n = arr.size();
    Node *root = NULL;
    for(auto i=n-1;i>=0;i--){
        Node *temp = NULL;
        root = insert(root,arr[i],temp);
        if(temp)
            arr[i] = temp->data;
        else
            arr[i] = -1;
    }
    return arr;
}






