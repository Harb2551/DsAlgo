// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    vector <string> ans;
    vector <vector <int>> visited;
    void dfs(int i,int j,string s,vector <vector<int>> v,int n){
        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return;
        }
        if(i<0 || i>=n || j<0 || j>=n)
            return;
        if(v[i][j]==0 || visited[i][j])
            return;
        visited[i][j] = 1;
        dfs(i,j+1,s+'R',v,n);
        dfs(i,j-1,s+'L',v,n);
        dfs(i+1,j,s+'D',v,n);
        dfs(i-1,j,s+'U',v,n);
        visited[i][j] = 0;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string s;
        visited.resize(n,vector <int>(n,0));
        if(m[0][0]==0 || m[n-1][n-1]==0)
            return ans;
        dfs(0,0,s,m,n);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends