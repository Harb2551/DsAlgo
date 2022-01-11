// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    void build(int &n,vector <vector<int>> &board,vector <vector<int>> &ans){
        vector <int> v(n);
        for(auto i=0;i<n;i++){
            for(auto j=0;j<n;j++){
                if(board[i][j]){
                    v[i] = j+1;
                }
            }
        }
        ans.push_back(v);
    }
    
    void solve(int row,int col,int &n,int q,vector <vector<int>> &board,vector <vector<int>> &ans,long &a,long &b,long &c){
        if(q==n){
            build(n,board,ans);
            return;
        }
        if(col==n){
            row++;
            col = 0;
        }
        if(row==n)
            return;
        if((a&(1<<col))==0 and (b&(1<<(row+col)))==0 and (c&(1<<(row-col+n-1)))==0){
            a = a|(1<<col);
            b = b|(1<<(row+col));
            c = c|(1<<(row-col+n-1));
            board[row][col] = 1;
            solve(row+1,0,n,q+1,board,ans,a,b,c);
            board[row][col] = 0;
            a = a&(~(1<<col));
            b = b&(~(1<<(row+col)));
            c = c&(~(1<<(row-col+n-1)));
        }
        solve(row,col+1,n,q,board,ans,a,b,c);
    }
    
    vector<vector<int>> nQueen(int n) {
        // code here
        vector <vector<int>> board(n,vector<int>(n,0));
        vector <vector<int>> ans;
        int q = 0,row=0,col=0;
        long a=0,b=0,c=0;
        solve(row,col,n,q,board,ans,a,b,c);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends