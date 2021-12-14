// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

void preorder(Node* root){
    if(!root){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}


 // } Driver Code Ends
//function Template for C++

/*
Structure of the node of the binary tree is as
struct Node {
	int data;
	struct Node* left, *right;
};
*/
// you are required to complete this function
// the function and return an vector of Node
// which contains all the duplicate sub-tree

 unordered_map <string,int> mp1;
 unordered_map <string,Node*> mp2;
 vector <string> v1;
 
 string solve(Node *root){
     if(root==NULL)
        return "N";
     string s1 = solve(root->left);
     string s2 = solve(root->right);
     string s;
     int temp = root->data;
     while(temp!=0){
         s.push_back('0'+temp%10);
         temp /= 10;
     }
    //  cout << s << endl;
     reverse(s.begin(),s.end());
     string ans = s1+s+s2;
     mp1[ans]++;
     mp2[ans] = root;
     if(mp1[ans]==1)
        v1.push_back(ans);
     return ans;
 }

vector<Node*> printAllDups(Node* root)
{
    // Code here
    mp1.clear();
    mp2.clear();
    v1.clear();
    string s = solve(root);
    vector <Node*> v;
    int n = v1.size();
    for(auto i=0;i<n;i++){
        if(mp1[v1[i]]>=2)
            v.push_back(mp2[v1[i]]);
    }
    return v;
}

// { Driver Code Starts.
int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string treeString;
		getline(cin,treeString);
		Node* root = buildTree(treeString);
		vector<Node*> res = printAllDups(root);
		
		for(int i=0;i<res.size();i++){
		    preorder(res[i]);
		    cout<<endl;
		}
    }
    return 0;
}


  // } Driver Code Ends