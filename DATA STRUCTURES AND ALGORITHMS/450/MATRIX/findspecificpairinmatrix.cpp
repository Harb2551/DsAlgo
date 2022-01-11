int findMaxValue(vector<vector<int>>& mat, int n) {
	// Write your code here.
    vector <vector<int>> dp(n,vector<int>(n,0));
    for(auto i=0;i<n;i++){
        for(auto j=0;j<n;j++){
            if(i==0 and j==0)
                dp[i][j] = mat[i][j];
            else if(j==0)
                dp[i][j] = min(mat[i][j],dp[i-1][j]);
            else if(i==0)
                dp[i][j] = min(mat[i][j],dp[i][j-1]);
            else
           	   dp[i][j] = min(min(mat[i][j],dp[i-1][j-1]),min(dp[i-1][j],dp[i][j-1]));
        }
    }
    long long ans = INT_MIN;
    for(auto i=1;i<n;i++){
        for(auto j=1;j<n;j++){
            long long a = mat[i][j]-dp[i-1][j-1];
            ans = max(a,ans);
        }
    }
    return ans;
}