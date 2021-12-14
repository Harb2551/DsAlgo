// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution {
public:
    map <int,int> mp;
    long long cost;
    vector <int> visited;
    bool generate(vector <vector <int>> graph[],int v,int k){
        visited[v] = 1;
        // cout << v << ' ';
        int n = graph[v].size();
        for(auto i=0;i<n;i++){
            if(!mp[graph[v][i][0]]){
                cost += graph[v][i][1];
                // cout << cost << ' ';
                if(cost>=k)
                    return true;
                mp[graph[v][i][0]] = 1;
                if(generate(graph,graph[v][i][0],k))
                    return true;
                mp[graph[v][i][0]] = 0;
                cost -= graph[v][i][1];
            }
        }
        return false;
    }
    
    bool pathMoreThanK(int V, int E, int k, int *a) 
    { 
       //  Code Here'
       mp.clear();
       visited.clear();
       visited.resize(V,0);
       cost = 0;
       vector <vector<int>> graph[V];
       for(auto i=0;i<3*E;i+=3){
           graph[a[i]].push_back({a[i+1],a[i+2]});
           graph[a[i+1]].push_back({a[i],a[i+2]});
       }
        mp[0] = 1;
       return generate(graph,0,k);
    } 
};




// { Driver Code Starts.


int main() {
	//code
    int t;cin >> t;
    while(t--)
    {
        int V, E, K;
        cin >> V >> E >> K;
        int a[3*E + 1];
        for(int  i=0;i<3*E;i++){
            cin >> a[i];
        }
        
        Solution obj;
        if(obj.pathMoreThanK(V, E, K, a)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        
    }
	return 0;
}  // } Driver Code Ends