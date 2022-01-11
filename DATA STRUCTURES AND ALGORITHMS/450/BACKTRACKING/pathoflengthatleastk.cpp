// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution {
public:
    
    vector <int> visited;

    bool solve(vector <vector<int>> graph[],int k,int s,int temp){
        if(temp>=k)
            return true;
        if(visited[s])
            return false;
        int n = graph[s].size();
        visited[s] = 1;
        for(auto i=0;i<n;i++){
            if(!visited[graph[s][i][0]]){
                if(solve(graph,k,graph[s][i][0],temp+graph[s][i][1]))
                    return true;
            }
        }
        visited[s] = 0;
        return false;
    }

    bool pathMoreThanK(int V, int E, int k, int *a) 
    { 
       //  Code Here 
       vector <vector<int>> graph[V];
       visited.clear();
       visited.resize(V,0);
       for(auto i=0;i<3*E;i+=3){
           graph[a[i]].push_back({a[i+1],a[i+2]});
           graph[a[i+1]].push_back({a[i],a[i+2]});
       }
       return solve(graph,k,0,0);
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