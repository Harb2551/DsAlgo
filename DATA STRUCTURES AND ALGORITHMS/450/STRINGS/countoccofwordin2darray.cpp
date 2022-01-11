// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    vector <vector<int>> visited;
    int count;
    
    void dfs(vector<vector<char>> &mat,string target,int i,int j,string temp,int in,int n,int m,int len){
        if(target[in]==mat[i][j]){
            if(in==len-1){
                count++;
                return;
            }
            else{
               visited[i][j] = 1; 
               if(i+1<n and !visited[i+1][j])
                    dfs(mat,target,i+1,j,temp+mat[i][j],in+1,n,m,len);
               if(i-1>=0 and !visited[i-1][j])
                    dfs(mat,target,i-1,j,temp+mat[i][j],in+1,n,m,len);
               if(j+1<m and !visited[i][j+1])
                    dfs(mat,target,i,j+1,temp+mat[i][j],in+1,n,m,len);
               if(j-1>=0 and !visited[i][j-1])
                    dfs(mat,target,i,j-1,temp+mat[i][j],in+1,n,m,len);
               visited[i][j] = 0;
            }
        }
    }
    
    int findOccurrence(vector<vector<char> > &mat, string target){
        int n = mat.size();
        int m = mat[0].size();
        count = 0;
        string temp;
        int len = target.length();
        visited.resize(n,vector<int>(m,0));
        for(auto i=0;i<n;i++){
            for(auto j=0;j<m;j++){
                dfs(mat,target,i,j,temp,0,n,m,len);
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
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    }
}
  // } Driver Code Ends

































