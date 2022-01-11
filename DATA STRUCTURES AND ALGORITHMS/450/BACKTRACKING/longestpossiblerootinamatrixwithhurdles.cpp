#include <bits/stdc++.h>
using namespace std;

vector <vector<int>> visited;

void solve(int n,int m,vector<vector<int>> &mat,int sx,int sy,int dx,int dy,int &ans,int temp){
    if(sx==dx and sy==dy){
      	ans = max(ans,temp);
        return;
    }
    visited[sx][sy] = 1;
    if(sx-1>=0 and !visited[sx-1][sy] and mat[sx-1][sy])
        solve(n,m,mat,sx-1,sy,dx,dy,ans,temp+1);
    if(sx+1<n and !visited[sx+1][sy] and mat[sx+1][sy])
        solve(n,m,mat,sx+1,sy,dx,dy,ans,temp+1);
    if(sy-1>=0 and !visited[sx][sy-1] and mat[sx][sy-1])
        solve(n,m,mat,sx,sy-1,dx,dy,ans,temp+1);
    if(sy+1<m and !visited[sx][sy+1] and mat[sx][sy+1])
        solve(n,m,mat,sx,sy+1,dx,dy,ans,temp+1);
    visited[sx][sy] = 0;
}

int longestPath(int n, int m, vector<vector<int>> &mat, int sx, int sy, int dx, int dy) {
	// Write your code here
    int ans = -1;
    visited.clear();
    visited.resize(n,vector<int>(m,0));
    if(mat[sx][sy]==0)
        return -1;
    solve(n,m,mat,sx,sy,dx,dy,ans,0);
    return ans;
}

