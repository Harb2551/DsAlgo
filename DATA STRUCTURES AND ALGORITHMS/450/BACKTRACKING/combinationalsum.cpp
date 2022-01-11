// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.  
    void solve(vector <int> &a,int b,int temp,int i,int n,vector <int> &cur,vector <vector<int>> &ans){
        if(temp>b)
            return;
        if(temp==b){
            ans.push_back(cur);
            return;
        }
        for(auto j=i;j<n;j++){
            cur.push_back(a[j]);
            solve(a,b,temp+a[j],j,n,cur,ans);
            cur.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int> &A, int B) {
        // Your code here
        int n = A.size();
        map <int,int> mp1;
        for(auto i=0;i<n;i++)
            mp1[A[i]]++;
        vector <int> a;
        for(auto i=mp1.begin();i!=mp1.end();i++)
            a.push_back(i->first);
        vector <vector<int>> ans;
        vector <int> cur;
        int temp = 0;
        solve(a,B,temp,0,a.size(),cur,ans);
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
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends