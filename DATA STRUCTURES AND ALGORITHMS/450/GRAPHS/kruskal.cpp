// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class edge{
    public:
    
    int u;
    int v;
    int e;
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	vector <int> parent;
	vector <int> rank;
	
	static bool compare(const edge &a,const edge &b){
	    return a.e<b.e;
	}
	
	void makeset(int n){
	    for(auto i=0;i<n;i++)
	        parent[i] = i;
	}
	
	int find(int i){
	    if(parent[i]==i)
	        return i;
        return parent[i] = find(parent[i]);
	}
	
	void union1(int i,int j){
	    int a = find(i);
	    int b = find(j);
	    if(a==b)
	        return;
	    if(rank[a]>rank[b])
	        parent[b] = a;
	    else if(rank[a]<rank[b])
	        parent[a] = b;
	    else{
	        parent[a] = b;
	        rank[b] += 1;
	    }
	}
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector <edge> graph;
        for(auto i=0;i<V;i++){
            for(auto j=0;j<adj[i].size();j++){
                edge a;
                a.u = i;
                a.v = adj[i][j][0];
                a.e = adj[i][j][1];
                graph.push_back(a);
            }
        }
        sort(graph.begin(),graph.end(),compare);
        rank.resize(V,1);
        parent.resize(V);
        int n = graph.size();
        makeset(V);
        int mincost=0;
        for(auto i=0;i<n;i++){
            if(find(graph[i].u)!=find(graph[i].v)){
                mincost += graph[i].e;
                union1(graph[i].u,graph[i].v);
            }
        }
        return mincost;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends