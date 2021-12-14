// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
map <int,int> mp;
bool mcolor(bool graph[101][101],int m,int v,int n){
    if(v==n)
        return true;
    map <int,int> color;
    for(auto j=0;j<n;j++){
        if(j!=v and graph[v][j]){
            if(mp[j])
                color[mp[j]] = 1;
        }
    }
    for(auto i=1;i<=m;i++){
        if(!color[i]){
            mp[v] = i;
            if(mcolor(graph,m,v+1,n))
                return true;
            mp[v] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    mp.clear();
    return mcolor(graph,m,0,V);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends