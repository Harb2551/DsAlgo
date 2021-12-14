// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:

    map <int,int> mp;
    int root;
    Node* buildtree(int in[],int pre[],int i,int j){
        if(i>j)
            return NULL;
        Node *temp = new Node(pre[root]);
        int index = mp[pre[root++]];
        if(i==j)
            return temp;
        auto l = buildtree(in,pre,i,index-1);
        auto r = buildtree(in,pre,index+1,j);
        temp->left = l;
        temp->right = r;
        return temp;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        root=0;
        mp.clear();
        for(auto i=0;i<n;i++)
            mp[in[i]] = i;
        return buildtree(in,pre,0,n-1);
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends  