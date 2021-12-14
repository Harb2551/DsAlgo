// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
int total_cost(vector<vector<int>>cost){
    // Code here
    int n = cost.size();
    vector <vector <int>> v(n+1);
    for(auto i=1;i<(1<<n);i++){
        int temp = i,count=0;
        while(temp){
            temp = temp&(temp-1);
            count++;
        }
        v[count].push_back(i);
    }
    vector <map <pair<long long,long long>,long long>> ans(n+1);
    ans[1][{1,0}] = 0;
    for(auto i=2;i<=n;i++){
        for(auto j=0;j<v[i].size();j++){
            ans[i][{v[i][j],0}] = INT_MAX; 
            for(auto k=0;k<n;k++){
                if(k!=0 and (v[i][j]&(1<<k)) and (v[i][j]&1)){
                    ans[i][{v[i][j],k}] = INT_MAX;
                    for(auto l=0;l<n;l++){
                        if(l!=k and (v[i][j]&(1<<l)) and ans[i][{v[i][j],k}]>ans[i-1][{v[i][j]^(1<<k),l}] + cost[l][k]){
                            ans[i][{v[i][j],k}] = ans[i-1][{v[i][j]^(1<<k),l}] + cost[l][k];
                        }
                    }
                }
            }
        }
    }
    long long  mincost = INT_MAX;
    for(auto i=ans[n].begin();i!=ans[n].end();i++){
        mincost = min(mincost,(i->second)+cost[((i->first).second)][0]);
    }
    return mincost;
}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends