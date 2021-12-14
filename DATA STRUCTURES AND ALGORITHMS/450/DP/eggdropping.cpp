// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    
    int eggDrop(int n, int k) 
    {
        // your code here
        int dp[n+1][k+1];
        for(auto i=1;i<=n;i++){
            for(auto j=0;j<=k;j++){
                if(i==1)
                    dp[i][j] = j;
                else if(j==0 || j==1)
                    dp[i][j] = j;
            }
        }
      for(auto e=2;e<=n;e++){
        for(auto i=2;i<=k;i++){
            int ans = INT_MAX;
            for(auto j=1;j<=i-1;j++){
                int temp = 1+max(dp[e-1][j-1],dp[e][i-j]);
                ans = min(ans,temp);
            }
            dp[e][i] = ans;
        }
      }
      return dp[n][k];
    }
    
    // for memoization
    int eggdrop(int n,int k){
        if(dp[n][k]!=-1)
            return dp[n][k];
        if(n==1)
            return dp[n][k] = k;
        if(k==1 || k==0)
            return dp[n][k] = k; 
        int ans = INT_MAX;
        for(auto i=1;i<=k-1;i++){
            int temp = 1+max(eggdrop(n-1,i-1),eggdrop(n,k-i));
            ans = min(ans,temp);
        }
        return dp[n][k] = ans;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends