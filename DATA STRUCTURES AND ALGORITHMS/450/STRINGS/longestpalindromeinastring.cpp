// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        // code here
        int n = S.length();
        int dp[n+1][n+1];
        int a=-1,b=-1;
        int diff = -1;
        memset(dp,-1,sizeof(dp));
        for(auto s=0;s<n;s++){
            for(auto i=0;i<n-s;i++){
                int j = i+s;
                if(i==j)
                    dp[i][j] = 1;
                else if(j==i+1){
                    if(S[i]==S[j])
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                }
                else{
                    if(S[i]==S[j] and dp[i+1][j-1])
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                }
                if(dp[i][j] and j-i>diff){
                    diff = j-i;
                    a = i;
                    b = j;
                }
            }
        }
        return S.substr(a,b-a+1);
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends