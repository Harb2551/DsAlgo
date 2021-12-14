// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int minSteps(int m, int n, int d)
	{
	    // Code here
	    queue <pair<int,int>> q;
	    map <pair<int,int>,int> visited;
	    q.push({0,0});
	    visited[{0,0}] = 1;
	    int mov = -1;
	    while(!q.empty()){
	        mov++;
	        int size = q.size();
	      for(auto i=0;i<size;i++){
	        auto cur = q.front();
	        int u = cur.first;
	        int v = cur.second;
	        q.pop();
	        if(u==d || v==d)
	            return mov;
	        if(u>0 && !visited[{0,v}]){
	            visited[{0,v}] = 1;
	            q.push({0,v});
	        }
	        if(v>0 && !visited[{u,0}]){
	            visited[{u,0}] = 1;
	            q.push({u,0});
	        }
	        if(u==0 && !visited[{m,v}]){
	            visited[{m,v}] = 1;
	            q.push({m,v});
	        }
	        if(v==0 && !visited[{u,n}]){
	            visited[{u,n}] = 1;
	            q.push({u,n});
	        }
	        if(u>0){
	            if(u>=n-v && !visited[{u-(n-v),n}]){
	                visited[{u-(n-v),n}] = 1;
	                q.push({u-(n-v),n});
	            }
	            else if(u<n-v && !visited[{0,v+u}]){
	                visited[{0,v+u}] = 1;
	                q.push({0,v+u});
	            }
	        }
	        if(v>0){
	            if(v>=m-u && !visited[{m,v-(m-u)}]){
	                visited[{m,v-(m-u)}] = 1;
	                q.push({m,v-(m-u)});
	            }
	            else if(v<m-u && !visited[{u+v,0}]){
	                visited[{u+v,0}] = 1;
	                q.push({u+v,0});
	            }
	        }
	      }
	    }
	    return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, d;
		cin >> m >> n >> d;
		Solution ob;
		int ans = ob.minSteps(m, n, d);
		cout << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends