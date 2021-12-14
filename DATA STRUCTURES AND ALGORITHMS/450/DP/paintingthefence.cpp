// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    int mod = 1000000007;
    
    long long countWays(int n, int k){
        // code here
        if(n==1)
            return k;
        long long dp[n+1][2];
        long long diff = k;
        long long same = 0;
        for(auto i=n-1;i>=1;i--){
            long long temp = diff;
            diff = (((k-1)*same)%mod + ((k-1)*diff)%mod)%mod;
            same = temp;
        }
        return (diff+same)%mod;
    }
    
    // for memoization
    long long countways(int n,int k,int i,int color){
        long long count = 0;
        if(dp[i][color]!=-1)
            return dp[i][color];
        if(i==n)
            return dp[i][color]=1;
        if(color==0)
            count += countways(n,k,i+1,1);
        count %= mod;
        count += (k-1)*countways(n,k,i+1,0);
        return dp[i][color] = count%mod;
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends