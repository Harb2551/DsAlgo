class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        vector <vector <int>> visited(n,vector <int> (m,0));
        vector <vector <int>> v(n,vector <int> (m,0));
        for(auto i=0;i<n;i++)
            for(auto j=0;j<m;j++)
                v[i][j] = image[i][j];
        queue <pair<int,int>> q;
        q.push({sr,sc});
        visited[sr][sc]=1;
        v[sr][sc] = newColor;
        while(!q.empty()){
            pair <int,int> p;
            p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;
            if(i-1>=0 && !visited[i-1][j] && image[i][j]==image[i-1][j]){
                visited[i-1][j] = 1;
                q.push({i-1,j});
                v[i-1][j] = newColor;
            }
            if(j-1>=0 && !visited[i][j-1] && image[i][j]==image[i][j-1]){
                visited[i][j-1] = 1;
                q.push({i,j-1});
                v[i][j-1] = newColor;
            }
            if(i+1<n && !visited[i+1][j] && image[i][j]==image[i+1][j]){
                visited[i+1][j] = 1;
                q.push({i+1,j});
                v[i+1][j] = newColor;
            }
            if(j+1<m && !visited[i][j+1] && image[i][j]==image[i][j+1]){
                visited[i][j+1] = 1;
                q.push({i,j+1});
                v[i][j+1] = newColor;
            }
        }
        return v;
    }
};