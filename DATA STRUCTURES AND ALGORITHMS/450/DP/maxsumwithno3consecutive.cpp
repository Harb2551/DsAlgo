int maxSum(vector<int> &a, int n) 
{
	// Write your code here.
    if(n==1)
        return a[0];
    else if(n==2)
        return a[0]+a[1];
    int dp[n];
    dp[0] = a[0];
    dp[1] = a[0] + a[1];
    dp[2] = max(a[0]+a[1],max(a[1]+a[2],a[0]+a[2]));
    for(auto i=3;i<n;i++){
       dp[i]=max(max(dp[i-1],dp[i-2]+a[i]),dp[i-3]+a[i-1]+a[i]);
    }
    return dp[n-1];
}