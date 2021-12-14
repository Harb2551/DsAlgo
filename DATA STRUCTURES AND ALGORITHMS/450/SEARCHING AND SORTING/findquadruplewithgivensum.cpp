// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required

    
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        int n = arr.size();
        map <int,int> mp1;
        sort(arr.begin(),arr.end());
        vector <vector <int>> v;   
        for(auto i=0;i<n-3;i++){
            for(auto j=i+1;j<n-2;j++){
                int p=j+1,q=n-1;
                while(p<q){
                    if(arr[i] + arr[j]+arr[p]+arr[q]==k){
                        vector <int> v1;
                        v1 = {arr[i],arr[j],arr[p],arr[q]};
                        v.push_back(v1);
                        p++;
                        q--;
                    }
                    else if(arr[i] + arr[j]+arr[p]+arr[q]<k)
                        p++;
                    else
                        q--;
                }
            }
        }
        set <vector <int>> s;
        for(auto i=v.begin();i!=v.end();i++){
            s.insert(*i);
        }
        v.clear();
        for(auto i=s.begin();i!=s.end();i++){
            v.push_back(*i);
        }
        return v;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends