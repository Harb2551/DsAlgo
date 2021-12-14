// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        int dp[n][m];
        memset(dp,-1,sizeof(dp));
        for(auto i=0;i<n;i++){
            for(auto j=0;j<m;j++){
                if(mat[i][j]==0)
                    dp[i][j] = 0;
                else if(i==n-1 || j==m-1)
                    dp[i][j] = mat[i][j];
            }
        }
        for(auto i=n-2;i>=0;i--){
            for(auto j=m-2;j>=0;j--){
                if(dp[i][j]==-1){
                    dp[i][j] = 1 + min(dp[i][j+1],min(dp[i+1][j],dp[i+1][j+1]));
                }
            }
        }
        int ans = INT_MIN;
        for(auto i=0;i<n;i++){
            for(auto j=0;j<m;j++){
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends