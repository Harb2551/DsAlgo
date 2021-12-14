// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    // for memoization
    long long solve(string str,int i,int j){
        if(i>j)
            return dp[i][j] = 0;
        if(i==j)
            return dp[i][j] = 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(str[i]==str[j])
            return dp[i][j] = (1+solve(str,i,j-1)%mod + solve(str,i+1,j)%mod)%mod;
        return dp[i][j] = (solve(str,i,j-1)%mod + solve(str,i+1,j)%mod - solve(str,i+1,j-1)%mod)%mod;
    }
    
    long long int  countPS(string str)
    {
       //Your code here.
       int mod = 1000000007;
       int n = str.length();
       long long dp[n][n];
       memset(dp,0,sizeof(dp));
       for(auto s=0;s<n;s++){
           for(auto i=0;i<n-s;i++){
               int j = s+i;
               if(s==0)
                 dp[i][j] = 1;
               else{
                 if(str[i]==str[j])
                    dp[i][j] = (1 + dp[i][j-1]%mod + dp[i+1][j]%mod)%mod;
                 else
                    dp[i][j] = (dp[i][j-1]%mod + dp[i+1][j]%mod - dp[i+1][j-1]%mod + mod)%mod;
               }
           }
       }
       return dp[0][n-1];
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends