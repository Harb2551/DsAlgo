// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    
    int editDistance(string s, string t) {
        // Code here
        int n = s.length();
        int m = t.length();
        int dp[n+1][m+1];
        for(auto i=0;i<=m;i++)
            dp[0][i] = i;
        for(auto i=0;i<=n;i++)
            dp[i][0] = i;
        for(auto i=1;i<=n;i++){
            for(auto j=1;j<=m;j++){
                if(s[i-1]==t[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }
        }
        return dp[n][m];
    }
    
    // for memoization
    int editdistance(string s,string t,int n,int m){
        if(dp[n][m]!=-1)
            return dp[n][m];
        if(n==0 && m==0)
            return dp[n][m] = 0;
        if(n==0)
            return dp[n][m] = m;
        if(m==0)
            return dp[n][m] = n;
        if(s[n-1]==t[m-1])
            return dp[n][m] = editdistance(s,t,n-1,m-1);
        return dp[n][m] = 1+min(min(editdistance(s,t,n-1,m-1),editdistance(s,t,n-1,m)),editdistance(s,t,n,m-1));
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends