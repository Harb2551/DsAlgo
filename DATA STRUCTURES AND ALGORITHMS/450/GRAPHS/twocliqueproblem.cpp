#include <bits/stdc++.h>
using namespace std;

bool isbipartite(vector <vector<int>> graph){
    int n = graph.size();
    vector <int> color(n,0);
    color[0] = 1;
    queue <int> q;
    q.push(0);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto i=0;i<graph[cur].size();i++){
            if(color[graph[cur][i]]){
                if(color[cur]==color[graph[cur][i]])
                    return false;
            }
            else{
                color[graph[cur][i]] = 3 - color[cur];
                q.push(graph[cur][i]);
            }
        }
    }
    return true;
}

bool twoCliques(int n, vector<vector<int>> &edgeList)
{
	// Write your code here
    vector <vector<int>> graph(n);
    vector <vector<int>> mat(n,vector<int>(n,0));
    int m = edgeList.size();
    for(auto i=0;i<m;i++){
        mat[edgeList[i][0]][edgeList[i][1]] = 1;
        mat[edgeList[i][1]][edgeList[i][0]] = 1;
    }
    for(auto i=0;i<n;i++){
        for(auto j=0;j<n;j++){
            if(i!=j and !mat[i][j])
                graph[i].push_back(j);
        }
    }
    return isbipartite(graph);
}




