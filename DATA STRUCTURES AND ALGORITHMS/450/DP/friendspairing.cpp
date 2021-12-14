// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int mod = 1000000007;
    
    int countFriendsPairings(int n) 
    { 
        // code here
        int dp[n+1];
        dp[1] = 1;
        dp[2] = 2;
        for(long long i=3;i<=n;i++){
            dp[i] = (dp[i-1]+((i-1)*dp[i-2])%mod)%mod;  
        }
        return dp[n];
    }
    
    // for memoization
    int countfriendsPairings(long long n,int dp[]){
        if (dp[n] != -1)
            return dp[n];
        if (n > 2)
            return dp[n] = ((countfriendsPairings(n - 1,dp))%mod + ((n - 1) * countfriendsPairings(n - 2,dp)%mod)%mod)%mod;
        else
            return dp[n] = n;
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
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends