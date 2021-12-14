// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int dp[N][N];
        for(auto i=0;i<N;i++)
            dp[N-1][i] = Matrix[N-1][i];
        for(auto i=N-2;i>=0;i--){
            for(auto j=0;j<N;j++){
                if(j==0)
                    dp[i][j] = Matrix[i][j] + max(dp[i+1][j+1],dp[i+1][j]);
                else if(j==N-1)
                    dp[i][j] = Matrix[i][j] + max(dp[i+1][j-1],dp[i+1][j]);
                else
                    dp[i][j] = Matrix[i][j] + max(max(dp[i+1][j-1],dp[i+1][j]),dp[i+1][j+1]);
            }
        }
        return *max_element(dp[0],dp[0]+N);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends