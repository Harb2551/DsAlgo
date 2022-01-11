// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    bool solve(Node *root,int &ma,int &mi,int &ans,int &size){
        if(root->left==NULL and root->right==NULL){
            ma = root->data;
            mi = root->data;
            size = 1;
            ans = max(size,ans);
            return true;
        }
        bool l=1,r=1;
        int size1=0,size2=0;
        pair <int,int> p1={INT_MIN,INT_MAX},p2={INT_MIN,INT_MAX};
        if(root->left){
            l = solve(root->left,ma,mi,ans,size);
            p1 = {ma,mi};
            size1 = size;
        }
        if(root->right){
            r = solve(root->right,ma,mi,ans,size);
            p2 = {ma,mi}; 
            size2 = size;
        }
        if(l and r and root->data>p1.first and root->data<p2.second){
            ans = max(ans,1+size1+size2);
            size = 1+size1+size2;
            ma = max(root->data,p2.first);
            mi = min(root->data,p1.second);
            return true;
        }
        return false;
    }
    
    int largestBst(Node *root)
    {
    	//Your code here
    	int ans=0,size=0,ma=0,mi=0;
    	bool temp = solve(root,ma,mi,ans,size);
    	return ans;
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}
  // } Driver Code Ends