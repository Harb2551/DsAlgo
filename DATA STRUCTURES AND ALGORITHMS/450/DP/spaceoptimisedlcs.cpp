// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int dp[2][y+1];
        bool bi;
        for(auto i=0;i<=x;i++){
            bi = i&1;
            for(auto j=0;j<=y;j++){
                if(i==0 || j==0){
                    dp[bi][j] = 0;
                }
                else if(s1[i-1]==s2[j-1])
                    dp[bi][j] = dp[1-bi][j-1]+1;
                else
                    dp[bi][j] = max(dp[1-bi][j],dp[bi][j-1]);
            }
        }
        return dp[bi][y];
    }
    
    // for memoization
    int lonsub(int x, int y, string s1, string s2){
        if(dp[x][y]!=-1)
            return dp[x][y];
        if(x==0 || y==0)
            return dp[x][y] = 0;
        if(s1[x-1]==s2[y-1])
            return dp[x][y] = lonsub(x-1,y-1,s1,s2)+1;
        return dp[x][y] = max(lonsub(x-1,y,s1,s2),lonsub(x,y-1,s1,s2));
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends