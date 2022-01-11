// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  
    vector<int> nsl(vector <int> v,int n){
        stack <pair<int,int>> s;
        vector <int> temp(n,0);
        for(auto i=0;i<n;i++){
            while(!s.empty() and s.top().first>=v[i]) s.pop();
            if(s.empty())   temp[i] = -1;
            else    temp[i] = s.top().second;
            s.push({v[i],i});
        }
        return temp;
    }
  
    vector <int> nsr(vector <int> v,int n){
        stack <pair<int,int>> s;
        vector <int> temp(n,0);
        for(auto i=n-1;i>=0;i--){
            while(!s.empty() and s.top().first>=v[i]) s.pop();
            if(s.empty())   temp[i] = n;
            else    temp[i] = s.top().second;
            s.push({v[i],i});
        }
        return temp;
    }
  
    int mah(vector <int> v,int n){
        vector <int> width(n),ans(n);
        vector <int> nr = nsr(v,n);
        vector <int> nl = nsl(v,n);
        int ma = INT_MIN;
        for(auto i=0;i<n;i++){
            width[i] = nr[i]-nl[i]-1;
            ans[i] = v[i]*width[i];
            ma = max(ma,ans[i]);
        }
        return ma;
    }
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        vector <int> v(m,0);
        int ans = INT_MIN;
        for(auto i=0;i<n;i++){
            for(auto j=0;j<m;j++){
                if(M[i][j])
                    v[j] += M[i][j];
                else
                    v[j] = 0;
            }
            ans = max(ans,mah(v,m));
        }
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends