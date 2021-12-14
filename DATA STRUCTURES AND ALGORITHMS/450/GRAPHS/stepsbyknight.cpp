// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.

	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    vector <vector <int>> visited(N,vector <int>(N,0));
        queue <pair<int,int>> q;
        q.push({KnightPos[0]-1,KnightPos[1]-1});
        visited[KnightPos[0]-1][KnightPos[1]-1] = 1;
        vector <vector <int>> dist(N,vector <int>(N,0));
        while(!q.empty()){
            pair <int,int> p;
            p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;
            if(i==TargetPos[0]-1 && j==TargetPos[1]-1){
                return dist[i][j];
            }
            if(i-1>=0 && j-2>=0 && visited[i-1][j-2]==0){
                q.push({i-1,j-2});
                visited[i-1][j-2] = 1;
                dist[i-1][j-2] = dist[i][j]+1;
            }
            if(i+1<N && j-2>=0 && visited[i+1][j-2]==0){
                q.push({i+1,j-2});
                visited[i+1][j-2] = 1;
                dist[i+1][j-2] = dist[i][j]+1;
            }
            if(i-1>=0 && j+2<N && visited[i-1][j+2]==0){
                q.push({i-1,j+2});
                visited[i-1][j+2] = 1;
                dist[i-1][j+2] = dist[i][j]+1;
            }
            if(i+1<N && j+2<N && visited[i+1][j+2]==0){
                q.push({i+1,j+2});
                visited[i+1][j+2] = 1;
                dist[i+1][j+2] = dist[i][j]+1;
            }
            if(i-2>=0 && j-1>=0 && visited[i-2][j-1]==0){
                q.push({i-2,j-1});
                visited[i-2][j-1] = 1;
                dist[i-2][j-1] = dist[i][j]+1;
            }
            if(i-2>=0 && j+1<N && visited[i-2][j+1]==0){
                q.push({i-2,j+1});
                visited[i-2][j+1] = 1;
                dist[i-2][j+1] = dist[i][j]+1;
            }
            if(i+2<N && j-1>=0 && visited[i+2][j-1]==0){
                q.push({i+2,j-1});
                visited[i+2][j-1] = 1;
                dist[i+2][j-1] = dist[i][j]+1;
            }
            if(i+2<N && j+1<N && visited[i+2][j+1]==0){
                q.push({i+2,j+1});
                visited[i+2][j+1] = 1;
                dist[i+2][j+1] = dist[i][j]+1;
            }
        }
        return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends