class Solution {
public:
    pair <int,int> pos(int i,int n){
        double j = i;
        int p = ceil(j/n);
        int q = i%n==0 ? n : i%n;
        if((p&1))
            q--;
        else
            q = n-q;
        return {p,q};
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector <int> visited(n*n+1,0);
        queue <int> q1;
        q1.push(1);
        int mov=0;
        visited[1] = 1;
        while(!q1.empty()){
          int m = q1.size();
          mov++;
          for(auto t=0;t<m;t++){
            int cur = q1.front();
            q1.pop();
            for(auto i=cur+1;i<=min(n*n,cur+6);i++){
                if(i==n*n)
                    return mov;
                pair <int,int> x = pos(i,n);
                int p = x.first;
                int q = x.second;
                if(!visited[i]){                    
                    if(board[n-p][q]==-1){
                        q1.push(i);
                        visited[i]=1;
                    }
                    else{
                        if(!visited[board[n-p][q]]){
                            pair <int,int> y = pos(board[n-p][q],n);
                            if(board[n-y.first][y.second]==-1)
                                visited[board[n-p][q]] = 1;
                            if(board[n-p][q]==n*n)
                                return mov;
                            q1.push(board[n-p][q]);
                        }
                    }
                }   
            }
          }
        }
        return -1;
    }
};