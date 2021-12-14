#include <bits/stdc++.h> 
using namespace std;

vector <int> preorder;
vector <int> postorder;
vector <int> parent;
vector <vector <int>> ans;
vector <int> visited;
int order;

void dfs(vector <vector <int>> &graph,int v){
    visited[v] = 1;
    preorder[v] = order++;
    for(auto i=0;i<graph[v].size();i++){
        if(!visited[graph[v][i]]){
            parent[graph[v][i]] = v;
            dfs(graph,graph[v][i]);
            if(preorder[v]<postorder[graph[v][i]])
                ans.push_back({v,graph[v][i]});
        }
    }
    int po=preorder[v];
    for(auto i=0;i<graph[v].size();i++){
        if(graph[v][i]!=parent[v]){
        	if(postorder[graph[v][i]]==-1)
            	po = min(preorder[graph[v][i]],po);
        	else
            	po = min(postorder[graph[v][i]],po);
        }
    }
    postorder[v] = po;
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
	vector <vector<int>> graph(v);
    preorder.clear();
    postorder.clear();
    visited.clear();
    parent.clear();
    ans.clear();
    visited.resize(v,0);
    preorder.resize(v,-1);
    postorder.resize(v,-1);
    parent.resize(v,-1);
    order = 1;
    for(auto i=0;i<e;i++){
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
    for(auto i=0;i<v;i++){
        if(!visited[i])
            dfs(graph,i);
    }
    return ans;
}





