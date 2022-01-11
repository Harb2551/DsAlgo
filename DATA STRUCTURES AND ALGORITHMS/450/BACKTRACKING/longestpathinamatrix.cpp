// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:

    vector <vector<int>> dp;

    int dfs(vector <vector<int>> &matrix,int n,int m,int i,int j){
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans = 0;
        if(i-1>=0 and matrix[i][j]<matrix[i-1][j])
            ans = max(ans,dfs(matrix,n,m,i-1,j));
        if(i+1<n and matrix[i][j]<matrix[i+1][j])
            ans = max(ans,dfs(matrix,n,m,i+1,j));
        if(j-1>=0 and matrix[i][j]<matrix[i][j-1])
            ans = max(ans,dfs(matrix,n,m,i,j-1));
        if(j+1<m and matrix[i][j]<matrix[i][j+1])
            ans = max(ans,dfs(matrix,n,m,i,j+1));
        return dp[i][j] = ans+1;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // Code here
        int ans = INT_MIN;
        int n = matrix.size();
        int m = matrix[0].size();
        dp.clear();
        dp.resize(n,vector<int>(m,-1));
        for(auto i=0;i<n;i++){
            for(auto j=0;j<m;j++){
              ans = max(ans,dfs(matrix,n,m,i,j));  
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends