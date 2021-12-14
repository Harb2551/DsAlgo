
vector <int> visited; 
vector <int> temp;
vector <int> parent;
bool dfs(vector<int> graph[],int v){
//     if(v==3)
//         cout << temp[0] << endl;
    visited[v] = 1;
    int n = graph[v].size();
    temp[v] = 1;
    for(auto i=0;i<n;i++){
        if(temp[graph[v][i]] and parent[v]!=graph[v][i])
            return false;
        if(!visited[graph[v][i]]){
            parent[graph[v][i]] = v;
            if(!dfs(graph,graph[v][i]))
                return false;
        }
    }
    temp[v] = 0;
    return true;
}

bool isGraphTree(int n, vector<vector<int>> &edgeList)
{
	// Write your code here
    visited.clear();
    temp.clear();
    parent.clear();
    vector<int> graph[n];
    parent.resize(n,-1);
    temp.resize(n,0);
    visited.resize(n,0);
    int m = edgeList.size();
    for(auto i=0;i<m;i++){
        graph[edgeList[i][0]].push_back(edgeList[i][1]);
        graph[edgeList[i][1]].push_back(edgeList[i][0]);
    }
    bool flag = false;
    int cc = 0;
    for(auto i=0;i<n;i++){
        if(!visited[i]){
            cc++;
            flag = dfs(graph,i);
            if(!flag)
                break;
        }
    }
    if(!flag or cc>1)
        return false;
    return true;
}




