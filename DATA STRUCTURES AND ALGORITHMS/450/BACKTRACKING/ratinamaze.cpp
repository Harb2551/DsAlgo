// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    vector <vector<int>> visited;
    
    void maze(vector <string> &v,vector <vector<int>> &m,int n,int row,int col,string &s){
        if(row==n-1 and col==n-1 and m[row][col]==1){
            v.push_back(s);
            return;
        }
        if(row-1>=0 and !visited[row-1][col] and m[row-1][col]){
            s.push_back('U');
            visited[row-1][col] = 1;
            maze(v,m,n,row-1,col,s);
            visited[row-1][col] = 0;
            s.pop_back();
        }
        if(row+1<n and !visited[row+1][col] and m[row+1][col]){
            s.push_back('D');
            visited[row+1][col] = 1;
            maze(v,m,n,row+1,col,s);
            visited[row+1][col] = 0;
            s.pop_back();
        }
        if(col-1>=0 and !visited[row][col-1] and m[row][col-1]){
            s.push_back('L');
            visited[row][col-1] = 1;
            maze(v,m,n,row,col-1,s);
            visited[row][col-1] = 0;
            s.pop_back();
        }
        if(col+1<n and !visited[row][col+1] and m[row][col+1]){
            s.push_back('R');
            visited[row][col+1] = 1;
            maze(v,m,n,row,col+1,s);
            visited[row][col+1] = 0;
            s.pop_back();
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string s;
        visited.clear();
        visited.resize(n,vector<int>(n,0));
        vector <string> v;
        visited[0][0] = 1;
        if(m[0][0]!=0)
            maze(v,m,n,0,0,s);
        sort(v.begin(),v.end());
        return v;
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