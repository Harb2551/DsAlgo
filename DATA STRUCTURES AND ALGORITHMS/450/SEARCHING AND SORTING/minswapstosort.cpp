// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector <int> ans = nums;
	    map <int,int> mp;
	    int count = 0;
	    sort(ans.begin(),ans.end());
	    for(auto i=0;i<nums.size();i++){
	        mp[nums[i]] = i;
	    }
	    for(auto i=0;i<nums.size();i++){
	        if(nums[i]!=ans[i]){
	            int temp = nums[i];
	            swap(nums[i],nums[mp[ans[i]]]);
	            mp[temp] = mp[ans[i]];
	            mp[ans[i]] = i;
	            count++;
	        }
	    }
	    return count;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends