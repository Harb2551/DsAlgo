// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector <int> dp;
       for(auto i=0;i<=n;i++){
           dp.push_back(INT_MAX);
       }
       dp[1] = a[0]; 
       for(auto i=2;i<=n;i++){
           auto ans = upper_bound(dp.begin()+1,dp.end(),a[i-1]);
           if(a[i-1]<dp[ans-dp.begin()] && (ans==dp.begin()+1 || a[i-1]>dp[ans-dp.begin()-1]))
              dp[ans-dp.begin()] = a[i-1];
       }
       for(auto i=n;i>=1;i--){
           if(dp[i]!=INT_MAX){
              return i;
           }
       }
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends