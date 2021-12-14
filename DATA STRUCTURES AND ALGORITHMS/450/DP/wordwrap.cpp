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
        int dp1[n][n];
        int dp2[n][n];
        int presum[n];
        presum[0] = nums[0];
        for(auto i=1;i<n;i++){
            presum[i] = presum[i-1]+nums[i];
        }
        for(auto s=0;s<n;s++){
            for(auto i=0;i<n-s;i++){
                int j = s+i;
                if(i==j){
                    dp1[i][j] = 0;
                    dp2[i][j] = pow(k-nums[i],2);
                }
                else if(j-i==1){
                    int sum=presum[j]-presum[i]+nums[i];
                    if(sum+1<=k){
                        dp1[i][j] = 0;
                        dp2[i][j] = pow(k-sum-1,2);
                    }
                    else{
                        dp1[i][j] = dp2[i][i];
                        dp2[i][j] = dp2[i][i]+dp2[j][j];
                    }
                }
                else{
                    int sum=presum[j]-presum[i]+nums[i];
                    if(sum+j-i<=k){
                        dp1[i][j] = 0;
                        dp2[i][j] = pow(k-sum-(j-i),2);
                    }
                    else{
                        dp1[i][j] = INT_MAX;
                        for(auto k=i;k<j;k++){
                            int temp = dp2[i][k] + dp1[k+1][j];
                            if(temp<dp1[i][j]){
                                dp1[i][j] = temp;
                                dp2[i][j] = dp2[i][k] + dp2[k+1][j];
                            }
                        }
                    }
                }
            }
        }
        return dp1[0][n-1];
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