// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    
    unordered_map <string,int> dp;

    int solve(string a,unordered_map <string,int> mp){
        if(dp[a]!=0)
            return dp[a];
        int n = a.length();
        if(n==0 || mp[a])
            return dp[a] = 1;
        for(auto i=1;i<n;i++){
            if(mp[a.substr(0,i)] && solve(a.substr(i,n),mp)==1)
                return dp[a] = 1;
        }
        return dp[a] = -1;
    }
    
    int wordBreak(string A, vector<string> &B) {
        //code here
        unordered_map <string,int> mp;
        for(auto i=0;i<B.size();i++){
            mp[B[i]] = 1;
        }
        return solve(A,mp)==1 ? 1 : 0;
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