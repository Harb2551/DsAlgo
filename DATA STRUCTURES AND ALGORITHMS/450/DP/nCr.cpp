// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nCr(int n, int r){
        int mod = 1000000007;
        if(n<r)
          return 0;
        long long dp[n+1][r+1];
        memset(dp,-1,sizeof(dp));
        for(auto i=1;i<=n;i++){
            for(auto j=1;j<=r;j++){
                if(j==1)
                  dp[i][j] = i;
                if(i==j){
                  dp[i][j] = 1;
                }
            }
        }

        for(auto i=3;i<=n;i++){
            for(auto j=2;j<=r;j++){
                if(dp[i][j]==-1)
                dp[i][j] = (dp[i-1][j]%mod + dp[i-1][j-1]%mod)%mod;
            }
        }
        return dp[n][r];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends