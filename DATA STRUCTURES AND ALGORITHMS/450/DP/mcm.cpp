// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        int dp[N+1][N+1];
        for(auto i=0;i<N;i++){
            for(auto j=0;j<N;j++){
                if(i==j)
                    dp[i][j] = 0;
            }
        }
        for(auto s=1;s<N-1;s++){
            for(auto i=1;i<=N-s-1;i++){
                int j = s+i;
                int ans = INT_MAX;
                for(auto k=i;k<j;k++){
                    int temp = dp[i][k]+dp[k+1][j]+arr[i-1]*arr[j]*arr[k];
                    ans = min(ans,temp);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][N-1];
    }
    
    // for memoization
    int mcm(int arr[],int i,int j){
        if(i>=j)
          return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        auto ans = INT_MAX;
        for(auto k=i;k<j;k++){
            auto ans1 = mcm(arr,i,k);
            auto ans2 = mcm(arr,k+1,j);
            auto cost = ans1 + ans2 + arr[i-1]*arr[j]*arr[k];
            ans = min(ans,cost);
        }
        return dp[i][j] = ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends