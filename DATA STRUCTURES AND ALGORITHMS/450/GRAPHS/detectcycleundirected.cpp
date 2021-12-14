// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    vector <int> visited;
	vector <int> parent;
	
	bool dfs(int v, vector<int> adj[]){
	    visited[v] = 1;
	    int n = adj[v].size();
	    for(auto i=0;i<n;i++){
	        if(!visited[adj[v][i]]){
	           parent[adj[v][i]] = v;
	           if(dfs(adj[v][i],adj))
	                return true;
	        }
	        else if(adj[v][i]!=parent[v])
	            return true;
	    }
	    return false;
	}
    
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    visited.resize(V,0);
        parent.resize(V,-1);
	   	for(auto i=0;i<V;i++){
	   	    if(!visited[i]){
	   	        if(dfs(i,adj))
	   	            return true;
	   	    }
	   	}
	   	return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends