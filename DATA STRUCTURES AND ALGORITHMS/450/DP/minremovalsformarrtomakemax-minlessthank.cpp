#include <bits/stdc++.h>

int minRemovals(vector<int>& arr, int n, int k)
{
	// Write your code here.
    sort(arr.begin(),arr.end());
    int ans = INT_MAX;
    for(auto i=0;i<n;i++){
        int temp;
        if(arr[n-1]-arr[i]<=k)
            temp = i;
        else{
        	auto ub = upper_bound(arr.begin()+i+1,arr.end(),k+arr[i]);
        	int index = ub - arr.begin();
            temp = i+n-index;
        }
        ans = min(ans,temp);
    }
    return ans;
}
