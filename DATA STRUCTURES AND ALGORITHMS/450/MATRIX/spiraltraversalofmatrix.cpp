// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c) 
    {
        // code here 
        vector <int> ans;
        int sr=0,er=r-1,sc=0,ec=c-1;
        while(sr<=er and sc<=ec){
            for(auto j=sc;j<=ec;j++)
                ans.push_back(matrix[sr][j]);
            for(auto i=sr+1;i<er;i++)
                ans.push_back(matrix[i][ec]);
            if(sr!=er)
                for(auto j=ec;j>=sc;j--)
                    ans.push_back(matrix[er][j]);
            if(sc!=ec)
                for(auto i=er-1;i>sr;i--)
                ans.push_back(matrix[i][sc]);
            sr++;
            sc++;
            er--;
            ec--;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends