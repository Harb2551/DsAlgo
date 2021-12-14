// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
    int getMinDiff(int arr[], int n, int k) {
        // code here
        vector <pair<int,int>> v;
        for(auto i=0;i<n;i++){
            pair <int,int> p;
            p.first = arr[i]+k;
            p.second = i;
            v.push_back(p);
            if(arr[i]-k>=0){
                p.first = arr[i]-k;
                p.second = i;
                v.push_back(p);
            }
        }
        sort(v.begin(),v.end());
        int e=0,l=0,r=0,ans=INT_MAX;
        int visit[n];
        memset(visit,0,sizeof(visit));
        while(r<v.size()){
            while(e!=n && r<v.size()){
                if(visit[v[r].second]==0)
                    e++;
                visit[v[r].second]++;
                r++;
            }
            if(e==n){
                int x = v[r-1].first-v[l].first;
                if(x<ans)
                    ans = x;
                visit[v[l].second]--;
                if(visit[v[l].second]==0)
                        e--;
                l++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends