int count(vector <vector <int>> graph,bool dir){
    int n = graph.size();
    int cnt=0;
    for(auto i=0;i<n;i++){
        for(auto j=0;j<n;j++){
            for(auto k=0;k<n;k++){
                if(graph[i][j] and graph[j][k] and graph[k][i])
                    cnt++;
            }
        }
    }
    return dir==true ? cnt/3 : cnt/6;
}

vector<int> countTriangles(int v1, vector<vector<int>>& edgeListOfDirectedGraph, int v2,
			vector<vector<int>>& edgeListOfUnDirectedGraph) {
	// Write your code here.
    int m1 = edgeListOfDirectedGraph.size();
    int m2 = edgeListOfUnDirectedGraph.size();
    vector <vector<int>> graph1(v1,vector<int>(v1,0));
    vector <vector<int>> graph2(v2,vector<int>(v2,0));
    for(auto i=0;i<m1;i++){
        graph1[edgeListOfDirectedGraph[i][0]][edgeListOfDirectedGraph[i][1]] = 1;
    }
    for(auto i=0;i<m2;i++){
        graph2[edgeListOfUnDirectedGraph[i][0]][edgeListOfUnDirectedGraph[i][1]] = 1;
        graph2[edgeListOfUnDirectedGraph[i][1]][edgeListOfUnDirectedGraph[i][0]] = 1;
    }
    vector <int> v = {count(graph1,true),count(graph2,false)};
    return v;
}