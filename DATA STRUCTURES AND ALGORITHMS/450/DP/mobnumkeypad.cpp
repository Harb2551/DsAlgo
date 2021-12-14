// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{


	public:
	long long getCount(int N)
	{
		// Your code goes here
		map <int,vector<int>> mp;
		mp[0] = {8};
		mp[1] = {2,4};
		mp[2] = {1,3,5};
		mp[3] = {2,6};
		mp[4] = {1,5,7};
		mp[5] = {2,4,6,8};
		mp[6] = {3,5,9};
		mp[7] = {4,8};
		mp[8] = {5,7,9,0};
		mp[9] = {6,8};
		long long dp[10][N+1];
		for(auto j=1;j<=N;j++){
		    for(auto i=0;i<=9;i++){
		        if(j==1)
		            dp[i][j] = 1;
		        else{
		            dp[i][j] = dp[i][j-1];
		            for(auto k=mp[i].begin();k!=mp[i].end();k++){
		                dp[i][j] += dp[*k][j-1];
		            }
		        }
		    }
		}
		long long  ans=0;
		for(auto i=0;i<=9;i++)
		    ans += dp[i][N];
		return ans;
	}


};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends