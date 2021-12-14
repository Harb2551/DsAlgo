// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends

// for memoization
int lcs(string a,string b,string c,int p,int q,int r){
    if(dp[p][q][r]!=-1)
        return dp[p][q][r];
    if(p==0 || q==0 || r==0)
        return dp[p][q][r]=0;
    if(a[p-1]==b[q-1] && b[q-1]==c[r-1])
        return dp[p][q][r]=1+lcs(a,b,c,p-1,q-1,r-1);
    return dp[p][q][r]=max(max(lcs(a,b,c,p-1,q,r),lcs(a,b,c,p,q-1,r)),lcs(a,b,c,p,q,r-1));
}

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    int dp[n1+1][n2+1][n3+1];
    for(auto i=0;i<=n1;i++){
        for(auto j=0;j<=n2;j++){
            for(auto k=0;k<=n3;k++){
                if(i==0 || j==0 || k==0)
                    dp[i][j][k] = 0;
                else if(A[i-1]==B[j-1] && B[j-1] == C[k-1])
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                else
                    dp[i][j][k] = max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);
            }
        }
    }
    return dp[n1][n2][n3];
}

