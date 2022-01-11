#include <bits/stdc++.h>
using namespace std;

vector <vector<int>> visited;

void solve(vector <vector<int>> &mat,int m,int n,int i,int j,vector <vector<int>> &ans,vector <int> &temp){
    if(i==m-1 and j==n-1){
        ans.push_back(temp);
        return;
    }
    visited[i][j] = 1;
    if(i+1<m and !visited[i+1][j]){
        temp.push_back(mat[i+1][j]);
        solve(mat,m,n,i+1,j,ans,temp);
        temp.pop_back();
    }
    if(j+1<n and !visited[i][j+1]){
        temp.push_back(mat[i][j+1]);
        solve(mat,m,n,i,j+1,ans,temp);
        temp.pop_back();
    }
    visited[i][j] = 0;
}

vector<vector <int> > printAllpaths(vector<vector<int> > & mat , int m , int n)
{
    //Write Your Code Here. 
    visited.clear();
    visited.resize(m,vector<int>(n,0));
    vector <vector<int>> ans;
    vector <int> temp;
    temp.push_back(mat[0][0]);
    solve(mat,m,n,0,0,ans,temp);
    return ans;
}
