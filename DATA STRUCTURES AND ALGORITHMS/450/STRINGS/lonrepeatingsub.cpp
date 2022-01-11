// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.length();
		    int dp[n+1][n+1];
		    memset(dp,-1,sizeof(dp));
		    for(auto i=0;i<=n;i++){
		        for(auto j=0;j<=n;j++){
		            if(i==0 or j==0)
		                dp[i][j] = 0;
		            else{
		                if(i!=j and str[i-1]==str[j-1])
		                    dp[i][j] = dp[i-1][j-1]+1;
		                else
		                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		            }
		        }
		    }
		    return dp[n][n];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends