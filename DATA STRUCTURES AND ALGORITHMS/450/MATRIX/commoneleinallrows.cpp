#include <bits/stdc++.h>
using namespace std;

vector<int> findCommonElements(vector<vector<int>> &mat)
{
    int M = mat.size();
    int N = mat[0].size();
    vector <int> ans;
    unordered_map<int, int> mp;
    for (int j = 0; j < N; j++)
        mp[mat[0][j]] = 1;
    if(M==1){
        for(auto j=0;j<N;j++)
            ans.push_back(mat[0][j]);
    }
    for (int i = 1; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (mp[mat[i][j]] == i)
            {
                mp[mat[i][j]] = i + 1;
                if (i==M-1 && mp[mat[i][j]]==M)
                  ans.push_back(mat[i][j]);
            }
        }
    }
    return ans;
}
