// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
       //Your code here
       int mod = 1000000007;
       int n = str.length();
       vector <vector<int>> dp(n,vector<int>(n,0));
       for(auto s=0;s<n;s++){
           for(auto i=0;i<n-s;i++){
               int j = i+s;
               if(i==j)
                  dp[i][j] = 1;
               else if(j==i+1){
                   if(str[i]==str[j])
                        dp[i][j] = 3;
                   else
                        dp[i][j] = 2;
               }
               else{
                   if(str[i]==str[j])
                       dp[i][j] = (dp[i+1][j] + dp[i][j-1] + 1)%mod;
                   else
                       dp[i][j] = ((dp[i][j-1] + dp[i+1][j])%mod - dp[i+1][j-1] + mod)%mod;
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