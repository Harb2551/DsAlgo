// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	vector <int> visited;
	vector <int> order;
	bool dfs(int v, vector<int> adj[]){
	    visited[v] = 1;
	    order[v] = 1;
	    int n = adj[v].size();
	    for(auto i=0;i<n;i++){
	        if(order[adj[v][i]])
	           return true;
	        if(!visited[adj[v][i]]){
	           if(dfs(adj[v][i],adj))
	                return true;
	        }
	    }
	    order[v]  = 0;
	    return false;
	}
	
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// code here
	   	visited.resize(V,0);
	   	order.resize(V,0);
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


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends