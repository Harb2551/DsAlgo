// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

struct Node{
    struct Node* children[26];
    int sp=0;
};

class Trie{
    public:
        struct Node *root;
        Trie(){
            root = new Node();
        }
        void insert(string word){
            Node *temp = root;
            int n = word.length();
            for(auto i=0;i<n;i++){
                 if(!temp->children[word[i]-'a']){
                    temp->children[word[i]-'a'] = new Node(); 
                    for(auto j=0;j<26;j++){
                        temp->children[word[i]-'a']->children[j] = NULL;
                    }
                }
                temp = temp->children[word[i]-'a'];   
                temp->sp++;
            }
        }
};

class Solution
{
    public:
    vector<string> findPrefixes(string arr[], int n)
    {
        //code here
        Trie trie;
        for(auto i=0;i<n;i++){
            trie.insert(arr[i]);
        }
        Node *temp = trie.root;
        vector <string> v;
        for(auto i=0;i<n;i++){
            string s;
            temp = trie.root;
            for(auto j=0;j<arr[i].length();j++){
                s += arr[i][j];
                temp = temp->children[arr[i][j]-'a'];
                if(temp->sp==1){
                    v.push_back(s);
                    break;
                }
            }
        }
        return v;
    }
    
};
// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}
  // } Driver Code Ends