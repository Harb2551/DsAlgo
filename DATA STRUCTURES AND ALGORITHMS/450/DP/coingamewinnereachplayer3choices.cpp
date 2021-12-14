int coinGameWinner(int n, int a, int b)
{
	// Write your code here.
    int dp[n+1];
    dp[1]=1;
    dp[a]=1;
    dp[b]=1;
    for(auto i=2;i<=n;i++){
        if(i!=a && i!=b){
            if(i>a && i>b && (dp[i-a]==0 || dp[i-b]==0 || dp[i-1]==0))
               dp[i] = 1;
            else if(i>a && (dp[i-a]==0 || dp[i-1]==0))
                dp[i] = 1;
            else if(i>b && (dp[i-b]==0||dp[i-1]==0))
                dp[i] = 1;
            else if(dp[i-1]==0)
                dp[i] = 1;
            else
                dp[i] = 0;
        }
    }
    return dp[n];
}

