// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    int m = edges.size();
	    vector <long long> dist(n,INT_MAX);
	    dist[0] = 0;
	    for(auto i=0;i<n;i++){
	        for(auto j=0;j<m;j++){
	            if(dist[edges[j][0]] != INT_MAX and dist[edges[j][1]]>dist[edges[j][0]]+edges[j][2]){
	                dist[edges[j][1]] = dist[edges[j][0]]+edges[j][2];
	                if(i==n-1)
	                    return true;
	            }
	        }
	    }
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends