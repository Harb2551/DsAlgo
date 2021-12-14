#include <bits/stdc++.h>

vector <int> visited;
vector <int> postorder;

void dfs(vector <vector<int>> graph[],int &v){
    visited[v] = 1;
    int n = graph[v].size();
    for(auto i=0;i<n;i++){
        if(!visited[graph[v][i][0]])
            dfs(graph,graph[v][i][0]);
    }
    postorder.push_back(v);
}

vector<int> findMaxDistances(int n, int src, vector<vector<int>> &edges) {
	/*
        Parameters of this function are -:
        'n': Number of nodes in given directed graph.
        'src': Source node.
        'edges': list of all edges, such that the 'ith edge is a 
                 directed edge from 'edges[i][0]' to 'edges[i][1]' and have weight 'edges[i][2]'. 
    */

    // Write your code here.
    vector <vector<int>> graph[n];
    int m = edges.size();
    for(auto i=0;i<m;i++){
		graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
    }
    visited.clear();
    visited.resize(n,0);
    postorder.clear();
    for(auto i=0;i<n;i++){
        if(!visited[i]){
            dfs(graph,i);
        }
    }
    reverse(postorder.begin(),postorder.end());
    vector <int> dist(n,-1);
    dist[src]=0;
    for(auto i=0;i<n;i++){
        if(dist[postorder[i]]!=-1){
            for(auto j=0;j<graph[postorder[i]].size();j++){
                if(dist[graph[postorder[i]][j][0]]<dist[postorder[i]]+graph[postorder[i]][j][1])
                    dist[graph[postorder[i]][j][0]] = dist[postorder[i]]+graph[postorder[i]][j][1];
            }
        }
    }
    return dist;
}
















