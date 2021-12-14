// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        int count=0;
        map <int,int> mp;
        for(auto i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(auto i=0;i<n;i++){
            if(mp[k-arr[i]]>0){
                if(k-arr[i]==arr[i]){
                    count += mp[k-arr[i]]-1;
                    mp[arr[i]]--;
                    continue;
                }
                count += mp[k-arr[i]];
                mp[arr[i]]--;
            }
        }
        return count;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}  // } Driver Code Ends