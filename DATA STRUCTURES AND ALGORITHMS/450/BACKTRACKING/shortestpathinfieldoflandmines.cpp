#include <bits/stdc++.h>
using namespace std;

vector <vector<int>> visited;

void solve(vector<vector<int>> &field,int i,int j,int n,int m,int &ans,int temp){
	if(j==m-1){
		ans = min(ans,temp);
		return;
	}  
    if(temp>=ans)
        return;
    visited[i][j] = 1;
    if(i-1>=0 and !visited[i-1][j] and field[i-1][j]) solve(field,i-1,j,n,m,ans,temp+1);
	if(i+1<n and !visited[i+1][j] and field[i+1][j]) solve(field,i+1,j,n,m,ans,temp+1);
	if(j-1>=0 and !visited[i][j-1] and field[i][j-1]) solve(field,i,j-1,n,m,ans,temp+1);
	if(j+1<m and !visited[i][j+1] and field[i][j+1]) solve(field,i,j+1,n,m,ans,temp+1);
    visited[i][j] = 0;
}

int shortestPath(vector<vector<int>> &field)
{
	// Write your code here.
	int n = field.size();
	int m = field[0].size();
	for(auto i=0;i<n;i++){
		for(auto j=0;j<m;j++){
			if(field[i][j]==0){
				if(i-1>=0 and field[i-1][j]!=0) field[i-1][j] = -1;
				if(i+1<n and field[i+1][j]!=0) field[i+1][j] = -1;
				if(j-1>=0 and field[i][j-1]!=0) field[i][j-1] = -1;
				if(j+1<m and field[i][j+1]!=0) field[i][j+1] = -1;
			}
		}
	}
	for(auto i=0;i<n;i++){
		for(auto j=0;j<m;j++){
			if(field[i][j]==-1)
				field[i][j] = 0;
		}
	}
	int ans = INT_MAX;
    visited.clear();
    visited.resize(n,vector<int>(m,0));
	for(auto i=0;i<n;i++){
        visited.clear();
    	visited.resize(n,vector<int>(m,0));
		solve(field,i,0,n,m,ans,0);
	}
	return ans==INT_MAX ? -1 : ans;
}
