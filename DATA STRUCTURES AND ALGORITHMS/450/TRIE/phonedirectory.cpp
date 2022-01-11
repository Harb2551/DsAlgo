// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

struct Node{
    Node* children[26];
    vector <int> v;
};

class Trie{
 public:
  Node* root;
  Trie(){
      root = new Node();
  }
  void insert(string word,int index){
      Node *temp = root;
      int n = word.length();
      for(auto i=0;i<n;i++){
          if(!temp->children[word[i]-'a']){
              temp->children[word[i]-'a'] = new Node();
          }
          temp = temp->children[word[i]-'a'];
          temp->v.push_back(index);
      }
  }
  
  vector <vector<string>> search(string s,string contact[]){
      vector <vector<string>> ans;
      int n = s.size();
      Node *temp = root;
      for(auto i=0;i<n;i++){
          temp = temp->children[s[i]-'a'];
          if(temp==NULL){
              while(i<n){
                  ans.push_back({"0"});
                  i++;
              }
              break;
          }
          int m = temp->v.size();
          set <string> v1;
          for(auto j=0;j<m;j++){
              v1.insert(contact[temp->v[j]]);
          }
          vector <string> t;
          for(auto j=v1.begin();j!=v1.end();j++)
            t.push_back(*j);
          ans.push_back(t);
      }
      return ans;
  }
};

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        Trie trie;
        for(auto i=0;i<n;i++){
            trie.insert(contact[i],i);
        }
        return trie.search(s,contact);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends