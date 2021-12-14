// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int kadane(vector <int> v,int n){
        int max_sum=INT_MIN,sum=0;
        for(auto i=0;i<n;i++){
            sum += v[i];
            max_sum = max(max_sum,sum);
            if(sum<0) sum = 0;
        }
        return max_sum;
    }
  
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        int ans=INT_MIN;
        for(auto i=0;i<R;i++){
            vector <int> x(C);
            for(auto j=i;j<R;j++){
                for(auto k=0;k<C;k++){
                    x[k] += M[j][k];
                }
                int temp = kadane(x,C);
                ans = max(temp,ans);
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
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends