// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        int dp[n+2][m+1];
        memset(dp,0,sizeof(dp));
        for(auto i=m-1;i>=0;i--){
            for(auto j=1;j<=n;j++){
                dp[j][i] = M[j-1][i] + max(dp[j][i+1],max(dp[j-1][i+1],dp[j+1][i+1]));
            }
        }
        int ans = INT_MIN;
        for(auto i=1;i<=n;i++)
            ans = max(ans,dp[i][0]);
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
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends