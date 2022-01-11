// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        int n = nums.size();
        vector <vector<int>> space(n,vector<int>(n,0)),count(n,vector<int>(n,0));
        vector <int> ans(n+1,0);
        for(auto i=0;i<n;i++){
            space[i][i] = k-nums[i];
            for(auto j=i+1;j<n;j++){
                space[i][j] = space[i][j-1]-nums[j]-1;
            }
        }
        for(auto i=0;i<n;i++){
            for(auto j=0;j<n;j++){
                if(space[i][j]<0)
                    count[i][j] = INT_MAX;
                else if(j==n-1 and space[i][j]>=0)
                    count[i][j] = 0;
                else
                    count[i][j] = space[i][j]*space[i][j];
            }
        }
        ans[0] = 0;
        for(auto i=1;i<=n;i++){
            ans[i] = INT_MAX;
            for(auto j=1;j<=i;j++){
                if(ans[j-1]!=INT_MAX and count[j-1][i-1]!=INT_MAX and ans[j-1]+count[j-1][i-1]<ans[i]){
                    ans[i] = ans[j-1] + count[j-1][i-1];
                }
            }
        }
        return ans[n];
    } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends