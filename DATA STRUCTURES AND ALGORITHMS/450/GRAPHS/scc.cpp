// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	vector <int> visited;
	vector <int> postorder;
	
	void dfs(int v,vector <int> graph[]){
	    visited[v] = 1;
	    int n = graph[v].size();
	    for(auto i=0;i<n;i++){
	        if(!visited[graph[v][i]]){
	            dfs(graph[v][i],graph);
	        }
	    }
	    postorder.push_back(v);
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector <int> rgraph[V];
        for(auto i=0;i<V;i++){
            for(auto j=0;j<adj[i].size();j++)
                rgraph[adj[i][j]].push_back(i);
        }
        visited.resize(V,0);
        int scc=0;
        for(auto i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,rgraph);
            }
        }
        reverse(postorder.begin(),postorder.end());
        vector <int> postorder1 = postorder;
        visited.clear();
        visited.resize(V,0);
        for(auto i=0;i<V;i++){
            if(!visited[postorder1[i]]){
                scc++;
                dfs(postorder1[i],adj);
            }
        }
        return scc;
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
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends