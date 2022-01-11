// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    vector <vector<int>> dp;
    int solve(string &str,string &pattern,int n,int m){
        if(n==-1 and m==-1)
            return true;
        if(n==-1){
            while(m--){
                if(pattern[m]!='*')
                    return false;
            }
            return true;
        }
        if(m==-1)
            return false;
        if(dp[n][m]!=-1)
            return dp[n][m];
        if(pattern[m]==str[n] or pattern[m]=='?')
            return dp[n][m] = solve(str,pattern,n-1,m-1);
        else if(pattern[m]=='*')
            return dp[n][m] = solve(str,pattern,n-1,m) or solve(str,pattern,n,m-1);
        return false;
    }
    
    int wildCard(string pattern,string str)
    {
        int n = str.length();
        int m = pattern.length();
        dp.clear();
        dp.resize(n,vector<int>(m,-1));
        return solve(str,pattern,n-1,m-1);
    }
};

// { Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}
  // } Driver Code Ends