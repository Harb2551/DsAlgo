// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	vector<vector<int>> vec = uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}
// } Driver Code Ends


/*You are required to complete this function*/

struct Node{
  Node* children[2];
  int ew=0;
};

class Trie{
public:
  Node *root;
  Trie(){
      root = new Node();
  }
  void insert(int M[MAX][MAX],int row,int col,vector <vector<int>> &ans){
      Node *temp = root;
      vector <int> v;
      for(auto i=0;i<col;i++){
          v.push_back(M[row][i]);
          if(!temp->children[M[row][i]]){
              temp->children[M[row][i]] = new Node();
          }
          temp = temp->children[M[row][i]];
      }
      temp->ew++;
      if(temp->ew==1)
        ans.push_back(v);
  }
};

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
    //Your code here
    Trie trie;
    vector <vector<int>> ans;
    for(auto i=0;i<row;i++){
        trie.insert(M,i,col,ans);
    }
    return ans;
}