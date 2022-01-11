// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    
    bool check(int grid[N][N],int row,int col,int num){
        for(auto i=0;i<N;i++){
            if(grid[row][i]==num)
                return false;
        }
        for(auto i=0;i<N;i++){
            if(grid[i][col]==num)
                return false;
        }
        int r = row-row%3;
        int c = col-col%3;
        for(auto i=r;i<r+3;i++){
            for(auto j=c;j<c+3;j++){
                if(grid[i][j]==num)
                    return false;
            }
        }
        return true;
    }
    
    bool solve(int grid[N][N],int row,int col){
        if(col==N){
            row++;
            col = 0;
        }
        if(row==9)
            return true;
        if(grid[row][col]!=0){
            if(solve(grid,row,col+1))
                return true;
        }
        else{
            for(auto i=1;i<=9;i++){
                if(check(grid,row,col,i)){
                    grid[row][col] = i;
                    if(solve(grid,row,col+1))
                        return true;
                    grid[row][col] = 0;
                }
            }
        }
        return false;
    }
    
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        if(solve(grid,0,0)) 
            return true;
        return false;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here
        for(auto i=0;i<N;i++){
            for(auto j=0;j<N;j++){
                cout << grid[i][j] << ' ';
            }
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends