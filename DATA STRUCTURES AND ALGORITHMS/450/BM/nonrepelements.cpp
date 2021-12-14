// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int ans1=0;
        int n = nums.size();
        for(auto i=0;i<n;i++)
            ans1 ^= nums[i];
        ans1 = ans1&(~(ans1-1));
        int ans2=0,ans3=0;
        for(auto i=0;i<n;i++){
            if(nums[i]&ans1)
                ans2 ^= nums[i];
            else
                ans3 ^= nums[i];
        }
        if(ans2<ans3)
            return {ans2,ans3};
        return {ans3,ans2};
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends