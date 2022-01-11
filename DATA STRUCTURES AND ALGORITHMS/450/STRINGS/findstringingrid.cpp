// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    vector <vector<int>> visited;
    int flag;
    
    void dfs(vector <vector<char>> &grid, string &word,int i,int j,int m,int n,string temp,int in,int size,int dir){
        if(grid[i][j]!=word[in])
            return;
        if(in==size-1){
            flag = 1;
            return;
        }
        visited[i][j] = 1;
        if(i+1<n and !visited[i+1][j] and dir==1)
            dfs(grid,word,i+1,j,m,n,temp+grid[i][j],in+1,size,dir);
        if(i-1>=0 and !visited[i-1][j]and dir==2)
            dfs(grid,word,i-1,j,m,n,temp+grid[i][j],in+1,size,dir);
        if(j+1<m and !visited[i][j+1]and dir==3)
            dfs(grid,word,i,j+1,m,n,temp+grid[i][j],in+1,size,dir);
        if(j-1>=0 and !visited[i][j-1]and dir==4)
            dfs(grid,word,i,j-1,m,n,temp+grid[i][j],in+1,size,dir);
        if(i+1<n and j+1<m and !visited[i+1][j+1]and dir==5)
            dfs(grid,word,i+1,j+1,m,n,temp+grid[i][j],in+1,size,dir);
        if(i+1<n and j-1>=0 and !visited[i+1][j-1]and dir==6)
            dfs(grid,word,i+1,j-1,m,n,temp+grid[i][j],in+1,size,dir);
        if(i-1>=0 and j+1<m and !visited[i-1][j+1]and dir==7)
            dfs(grid,word,i-1,j+1,m,n,temp+grid[i][j],in+1,size,dir);
        if(i-1>=0 and j-1>=0 and !visited[i-1][j-1]and dir==8)
            dfs(grid,word,i-1,j-1,m,n,temp+grid[i][j],in+1,size,dir);
        visited[i][j] = 0;
    }                                               
    
	vector<vector<int>>searchWord(vector<vector<char>>&grid, string &word){
	    // Code here
	    int n = grid.size();
	    int m = grid[0].size();
	    int size = word.size();
	    string temp;
	    vector <vector<int>> v;
	    visited.resize(n,vector<int>(m,0));
	    for(auto i=0;i<n;i++){
	        for(auto j=0;j<m;j++){
	            for(auto k=1;k<=8;k++){
	                flag = 0;
	                dfs(grid,word,i,j,m,n,temp,0,size,k);
	                if(flag){
	                    v.push_back({i,j});
	                    break;
	                }
	            }
	        }
	    }
	    return v;
	}                                                                                                                                                  
};


// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
	}
	return 0;
}  // } Driver Code Ends