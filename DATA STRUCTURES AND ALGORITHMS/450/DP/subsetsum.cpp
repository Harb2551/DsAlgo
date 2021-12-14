// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = accumulate(arr,arr+N,0);
        if(sum&1)
            return false;
        return subsetsum(arr,N,sum/2);
    }
    
    bool subsetsum(int arr[],int N,int num){
        bool dp[N+1][num+1];
        for(auto i=0;i<=num;i++)
            dp[0][i] = false;
        for(auto i=0;i<=N;i++)
            dp[i][0] = true;
        for(auto i=1;i<=N;i++){
            for(auto j=1;j<=num;j++){
                if(arr[i-1]<=j)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[N][num];
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends