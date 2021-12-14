// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string str)
    {
        // code here  
        int n = str.length();
        int dp[n][n];
        for(auto s=0;s<n;s++){
            for(auto i=0;i<n-s;i++){
                int j = s+i;
                if(i==j){
                    dp[i][j] = 0;
                }
                else if(j-i==1){
                    dp[i][j] = str[i]==str[j] ? 0 : 1;
                }
                else{
                    if(str[i]==str[j] && dp[i+1][j-1]==0)
                        dp[i][j] = 0;
                    else{
                        int ans = INT_MAX;
                        for(auto k=i;k<j;k++){
                            int temp = dp[i][k]+dp[k+1][j]+1;
                            ans = min(ans,temp);
                        }
                        dp[i][j] = ans;
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends