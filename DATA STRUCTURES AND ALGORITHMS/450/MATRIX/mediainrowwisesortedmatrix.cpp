// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here 
        int n = r*c;
        int low = 1,high = 2000;
        int mid;
        while(low<=high){
            mid = (low+high) >> 1;
            int temp = 0;
            for(auto i=0;i<r;i++){
                auto l = upper_bound(matrix[i].begin(),matrix[i].end(),mid);
                temp += l==matrix[i].end() ? c : l-matrix[i].begin();
            }
            if(temp>ceil((r*c)/2))
                high = mid-1;
            else 
                low = mid+1;
        }
        return low;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends