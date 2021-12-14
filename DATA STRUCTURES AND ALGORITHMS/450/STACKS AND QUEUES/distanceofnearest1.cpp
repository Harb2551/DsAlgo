// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    queue <pair<int,int>> q;
	    int n = grid.size();
	    int m = grid[0].size();
	    for(auto i=0;i<n;i++){
	        for(auto j=0;j<m;j++){
	            if(grid[i][j]==1){
	                grid[i][j] = 0;
	                q.push({i,j});
	            }
	            else
	                grid[i][j] = INT_MAX;
	        }
	    }
	    while(!q.empty()){
	        
	        int s = q.size();
	        for(auto p=0;p<s;p++){
	          auto cur = q.front();
	          q.pop();
	          int i = cur.first;
	          int j = cur.second;  
	          if(i+1<n and grid[i+1][j]>grid[i][j]+1){
	              grid[i+1][j] = grid[i][j] + 1;
	              q.push({i+1,j});
	          }
	          if(i-1>=0 and grid[i-1][j]>grid[i][j]+1){
	              grid[i-1][j] = grid[i][j] + 1;
	              q.push({i-1,j});
	          }
	          if(j+1<m and grid[i][j+1]>grid[i][j]+1){
	              grid[i][j+1] = grid[i][j] + 1;
	              q.push({i,j+1});
	          }
	          if(j-1>=0 and grid[i][j-1]>grid[i][j]+1){
	              grid[i][j-1] = grid[i][j] + 1;
	              q.push({i,j-1});
	          }
	        }
	}
	return grid;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends