// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

vector <int> dist;
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    
    static bool compare(const int a,const int b){
        return dist[a]>dist[b];
    }
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        dist.clear();
        dist.resize(V,INT_MAX);
        dist[S] = 0;
        priority_queue <int,vector <int>,function<bool(int,int)>> pq(compare);
        vector <bool> visited(V,0);
        pq.push(S);
        while(!pq.empty()){
            int cur = pq.top();
            pq.pop();
            int n = adj[cur].size();
            for(auto i=0;i<n;i++){
                if(dist[adj[cur][i][0]]>dist[cur]+adj[cur][i][1]){
                    dist[adj[cur][i][0]] = dist[cur]+adj[cur][i][1];
                    pq.push(adj[cur][i][0]);
                }
            }
        }
        return dist;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends