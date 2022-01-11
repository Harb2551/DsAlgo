#include <bits/stdc++.h>
using namespace std;

int max_index(vector <int> dist){
    int n = dist.size();
    int ans = INT_MIN;
    int index = -1;
    for(auto i=0;i<n;i++){
        if(ans<dist[i]){
            ans = dist[i];
            index = i;
        }
    }
    return index;
}

int kCenter(int n, int k, vector<vector<int>> &dist) {
    // Write your code here.
    vector <int> dist1(n,INT_MAX);
    int ans1 = 0;
    for(auto i=0;i<k;i++){
        for(auto j=0;j<n;j++){
            dist1[j] = min(dist1[j],dist[ans1][j]);
        }
        ans1 = max_index(dist1);
    }
    return dist1[ans1];
}





