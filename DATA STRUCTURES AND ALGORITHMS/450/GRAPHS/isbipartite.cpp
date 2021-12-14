// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    
    vector <int> color;
    
    bool bfs(int V,vector <int> adj[],int src){
        queue <int> q;
        q.push(src);
        color[src] = 1;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            int n = adj[cur].size();
            for(auto i=0;i<n;i++){
                if(color[adj[cur][i]]){
                    if(color[cur]==color[adj[cur][i]])
                        return false;
                }
                else{
                    color[adj[cur][i]] = 3-color[cur];
                    q.push(adj[cur][i]);
                }
            }
        }
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    color.resize(V,0);
        for(auto i=0;i<V;i++){
            if(!color[i]){
                if(!bfs(V,adj,i))
                    return false;
            }
        }
        return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends