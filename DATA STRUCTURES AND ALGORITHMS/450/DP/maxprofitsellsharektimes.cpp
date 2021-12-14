// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        // code here
        int dp[K+1][N+1];
        int m[K+1][N+1];
        for(auto i=0;i<=K;i++){
            for(auto j=0;j<=N-1;j++){
                if(i==0 || j==0){
                    dp[i][j] = 0;
                    m[i][j] = (j==0)?(-1)*A[j]:max(m[i][j-1],(-1)*A[j]);
                }
                else{
                    dp[i][j] = max(dp[i][j-1],m[i-1][j-1]+A[j]);
                    m[i][j] = max(m[i][j-1],dp[i][j]-A[j]);
                }
            }
        }
        return dp[K][N-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends