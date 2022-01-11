// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

struct Node{
    Node* children[26];
    vector <int> v;
};

class Trie{
    public:
    Node *root;
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
        }
        temp->v.push_back(index);
    }
};

class Solution{
  public:
  
    void solve(Node* temp,vector <vector<string>> &ans,vector<string> &string_list){
        if(!temp->v.empty()){
            int n = temp->v.size();
            vector <string> v1;
            for(auto i=0;i<n;i++){
                v1.push_back(string_list[temp->v[i]]);
            }
            ans.push_back(v1);
            return;
        }
        for(auto i=0;i<26;i++){
            if(temp->children[i])
                solve(temp->children[i],ans,string_list);
        }
    }
  
    vector<vector<string>> Anagrams(vector<string>& string_list) {
        //code here
        Trie trie;
        int n = string_list.size();
        for(auto i=0;i<n;i++){
            string s = string_list[i];
            sort(s.begin(),s.end());
            trie.insert(s,i);
        }
        vector <vector<string>> ans;
        solve(trie.root,ans,string_list);
        return ans;
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
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends