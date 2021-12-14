// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the number of islands.
    int visited[501][501];
    
    void dfs(vector <vector<char>> &v,int i,int j,int n,int m){
            if(i<0 or j<0 or i>=n or j>=m)
                return;
            if(v[i][j]=='0')
                return;
            if(!visited[i][j]){
            visited[i][j]=1;
            dfs(v,i-1,j,n,m);
            dfs(v,i+1,j,n,m);
            dfs(v,i-1,j-1,n,m);
            dfs(v,i-1,j+1,n,m);
            dfs(v,i+1,j-1,n,m);
            dfs(v,i+1,j+1,n,m);
            dfs(v,i,j+1,n,m);
            dfs(v,i,j-1,n,m);
            }
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int scc=0;
        for(auto i=0;i<n;i++){
            for(auto j=0;j<m;j++)
                visited[i][j]=0;
        }
        for(auto i=0;i<n;i++){
          for(auto j=0;j<m;j++){
            if(grid[i][j]=='1' and !visited[i][j]){
                scc++;
                dfs(grid,i,j,n,m);
            }
          }
        }
        return scc;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends