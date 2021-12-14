// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue <pair<int,int>> q;
        int r = grid.size();
        int c = grid[0].size();
        for(auto i=0;i<r;i++){
            for(auto j=0;j<c;j++){
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        int ans=0;
        while(!q.empty()){
            int m = q.size();
            for(auto p=0;p<m;p++){
                auto cur = q.front();
                int i = cur.first;
                int j = cur.second;
                q.pop();
                if(i+1<r and grid[i+1][j]==1){
                    q.push({i+1,j});
                    grid[i+1][j]=2;
                }
                if(i-1>=0 and grid[i-1][j]==1){
                    q.push({i-1,j});
                    grid[i-1][j]=2;
                }
                if(j-1>=0 and grid[i][j-1]==1){
                    q.push({i,j-1});
                    grid[i][j-1]=2;
                }
                if(j+1<c and grid[i][j+1]==1){
                    q.push({i,j+1});
                    grid[i][j+1]=2;
                }
            }
            if(!q.empty())
                ans++;
        }
        for(auto i=0;i<r;i++){
            for(auto j=0;j<c;j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return ans;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends