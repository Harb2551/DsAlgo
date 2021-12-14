// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(long long *arr, int n) {
	    // code here
	    long long maxprod=arr[0],minprod=arr[0],ans=arr[0],arr1[n];
	    for(auto i=1;i<n;i++){
	       long long temp = maxprod;
	       maxprod = max(arr[i],max(maxprod*arr[i],minprod*arr[i]));
	       minprod = min(arr[i],min(temp*arr[i],minprod*arr[i]));
	       if(ans<maxprod)
	        ans = maxprod;
	    }
	    return ans;
	}
	
	
};

// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, i;
        cin >> n;
        long long  arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends