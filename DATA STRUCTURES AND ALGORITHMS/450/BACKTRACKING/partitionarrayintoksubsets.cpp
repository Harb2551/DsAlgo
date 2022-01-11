// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    
    bool check(vector <vector<int>> &ans,int sum,int k){
        for(auto i=0;i<k;i++){
            int temp = 0;
            int n = ans[i].size();
            for(auto j=0;j<n;j++)
                temp += ans[i][j];
            if(temp!=sum)
                return false;
        }
        return true;
    }
    
    bool solve(int a[],int n,int i,vector <vector<int>> &ans,int k,int p,int sum){
        if(i==n){
            if(p==k){
                if(check(ans,sum,k))
                    return true;
            }
            return false;
        }
        for(auto j=0;j<k;j++){
            if(ans[j].empty()){
                ans[j].push_back(a[i]);
                if(solve(a,n,i+1,ans,k,p+1,sum))
                    return true;
                ans[j].pop_back();
                break;
            }
            ans[j].push_back(a[i]);
            if(solve(a,n,i+1,ans,k,p,sum))
                return true;
            ans[j].pop_back();
        }
        return false;
    }
  
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         int sum = accumulate(a,a+n,0);
         if(n<k or sum%k!=0)
            return false;
         vector <vector<int>> ans(k,vector<int>());
         return solve(a,n,0,ans,k,0,sum/k);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends