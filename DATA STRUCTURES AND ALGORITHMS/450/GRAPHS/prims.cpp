// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector <int> dist;
        int mincost=0;
        vector <int> visited(V,0);
        dist.resize(V,INT_MAX);
        priority_queue <pair<int,int>,vector<pair<int,int>>,greater <pair<int,int>>> pq;
        pq.push({0,0});
        dist[0] = 0;
        while(!pq.empty()){
            pair <int,int> cur = pq.top();
            pq.pop();
            if(visited[cur.second])
                continue;
            mincost += cur.first;
            visited[cur.second] = 1;
            int n = adj[cur.second].size();
            for(auto i=0;i<n;i++){
                if(!visited[adj[cur.second][i][0]] and dist[adj[cur.second][i][0]]>adj[cur.second][i][1]){
                    dist[adj[cur.second][i][0]] = adj[cur.second][i][1];
                    pq.push({dist[adj[cur.second][i][0]],adj[cur.second][i][0]});
                }
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