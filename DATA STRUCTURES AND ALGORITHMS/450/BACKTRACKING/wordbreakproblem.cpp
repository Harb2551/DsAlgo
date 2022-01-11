// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void solve(unordered_map <string,int> mp,string s,int i,int j,string &cur,vector <string> &ans){
        if(i>j){
            ans.push_back(cur);
            return;
        }
        string temp;
        for(auto k=i;k<=j;k++){
            temp.push_back(s[k]);
            if(mp[temp]){
                string t = cur;
                if(cur.empty())
                    cur = temp;
                else
                    cur += ' ' + temp;
                solve(mp,s,k+1,j,cur,ans);
                cur = t;
            }
        }
    }
    
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        unordered_map <string,int> mp;
        for(auto i=0;i<n;i++){
            mp[dict[i]] = 1;
        }
        string s1;
        vector <string> ans;
        solve(mp,s,0,s.length()-1,s1,ans);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends