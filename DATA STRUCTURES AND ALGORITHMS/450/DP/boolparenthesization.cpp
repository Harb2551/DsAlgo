// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countWays(int N, string S){
        // code here
        int t[N][N],f[N][N];
        memset(t,0,sizeof(t));
        memset(f,0,sizeof(f));
        for(auto s=0;s<N;s+=2){
            for(auto i=0;i<N-s;i+=2){
                int j = s+i;
                if(i==j){
                    t[i][j] = S[i]=='T' ? 1:0;
                    f[i][j] = S[i]=='T' ? 0:1;
                }
                else{
                    for(auto k=i+1;k<j;k+=2){
                        if(S[k]=='|'){
                            t[i][j] += t[i][k-1]*t[k+1][j] + t[i][k-1]*f[k+1][j] + f[i][k-1]*t[k+1][j];
                            f[i][j] += f[i][k-1]*f[k+1][j];
                        }
                        else if(S[k]=='&'){
                            t[i][j] += t[i][k-1]*t[k+1][j];
                            f[i][j] += f[i][k-1]*f[k+1][j] + f[i][k-1]*t[k+1][j] + t[i][k-1]*f[k+1][j];
                        }
                        else{
                            t[i][j] += t[i][k-1]*f[k+1][j] + f[i][k-1]*t[k+1][j];
                            f[i][j] += t[i][k-1]*t[k+1][j] + f[i][k-1]*f[k+1][j];
                        }
                    }
                }
            }
        }
        return t[0][N-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends