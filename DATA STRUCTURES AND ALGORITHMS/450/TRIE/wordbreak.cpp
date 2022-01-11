// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

struct Node{
  struct Node* children[26];
  bool isleaf = false;
};

class Trie{
  struct Node* root;
  public:
    Trie(){
         root = new Node();
    }
    void insert(string word){
        Node *temp = root;
        int n = word.length();
        for(auto i=0;i<n;i++){
            if(!temp->children[word[i]-'a'])
                temp->children[word[i]-'a'] = new Node();
            temp = temp->children[word[i]-'a'];
        }
        temp->isleaf = true;
    }
    
    bool search(string word){
        Node *temp = root;
        int n = word.length();
        for(auto i=0;i<n;i++){
            if(!temp->children[word[i]-'a'])
                return false;
            temp = temp->children[word[i]-'a'];
        }
        return temp->isleaf;
    }
};

class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
    
    bool solve(string A,Trie trie){
        int n = A.length();
        if(n==0)
            return true;
        for(auto i=1;i<=n;i++){
            if(trie.search(A.substr(0,i)) and solve(A.substr(i,n-i),trie))
                return true;
        }
        return false;
    }
    
    int wordBreak(string A, vector<string> &B) {
        //code here
        Trie trie;
        int n = B.size();
        for(auto i=0;i<n;i++)
            trie.insert(B[i]);
        return solve(A,trie);
    }
};
// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends