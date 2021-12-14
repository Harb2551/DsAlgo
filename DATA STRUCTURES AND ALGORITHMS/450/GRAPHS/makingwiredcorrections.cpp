class Solution {
public:
    
    vector <int> visited;
      
    void dfs(int v,vector <int> graph[]){
        visited[v] = 1;
        int n = graph[v].size();
        for(auto i=0;i<n;i++){
            if(!visited[graph[v][i]]){
                dfs(graph[v][i],graph);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(m<n-1)
            return -1;
        visited.resize(n,0);
        vector <int> graph[n];
        for(auto i=0;i<m;i++){
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        int scc=0;
        for(auto i=0;i<n;i++){
            if(!visited[i]){
                scc++;
                dfs(i,graph);
            }
        }
        return scc-1;
    }
};




