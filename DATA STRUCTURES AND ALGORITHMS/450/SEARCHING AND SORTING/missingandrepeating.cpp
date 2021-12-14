// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int rep,miss;
        for(auto i=0;i<n;i++){
            if(arr[abs(arr[i])-1]>0)
                arr[abs(arr[i])-1] *= -1;
            else{
                rep = abs(arr[i]);
            }
        }
        for(auto i=0;i<n;i++){
            if(arr[i]>0){
                miss = i+1;
                break;
            }
        }
        static int a[2];
        a[0] = rep;
        a[1] = miss;
        return a;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends