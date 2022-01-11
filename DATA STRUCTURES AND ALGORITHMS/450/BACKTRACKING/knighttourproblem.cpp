#include <bits/stdc++.h>
using namespace std;

vector <vector<int>> v;

int isSafe(int x, int y, vector <vector<int>> &sol,int n,int m)
{
    return (x >= 0 && x < n && y >= 0 && y < m
            && sol[x][y] == -1);
}

int solve(int x, int y, int movei, vector <vector<int>> &sol,
                int xMove[8], int yMove[8], int n,int m)
{
    int k, next_x, next_y;
    if (movei == n * m){
        v = sol;
        return 1;
    }
    
    for (k = 0; k < 8; k++) {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isSafe(next_x, next_y, sol,n,m)) {
            sol[next_x][next_y] = movei;
            if (solve(next_x, next_y, movei + 1, sol,xMove, yMove,n,m) == 1)
                return 1;
            else
                sol[next_x][next_y] = -1;
        }
    }
    return 0;
}

vector<vector<int>> knightTour(int n, int m) {
    vector <vector<int>> ans(n,vector<int>(m,-1));
    int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    v.clear();
    v.resize(n,vector<int>(m,-1));
    ans[0][0] = 0;
    int a = solve(0,0,1,ans,xMove,yMove,n,m);

    return v;
}




