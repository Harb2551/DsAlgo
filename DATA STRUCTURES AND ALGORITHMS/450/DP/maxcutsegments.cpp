// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        int dp[n+1];
        dp[0] = 0;
        for(auto i=1;i<=n;i++){
            int a=INT_MIN,b=INT_MIN,c=INT_MIN;
            if(x<=i)
                a = dp[i-x]+1;
            if(y<=i)
                b = dp[i-y]+1;
            if(z<=i)
                c = dp[i-z]+1;
            dp[i] = max(a,max(b,c));
        }
        return max(0,dp[n]);
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends