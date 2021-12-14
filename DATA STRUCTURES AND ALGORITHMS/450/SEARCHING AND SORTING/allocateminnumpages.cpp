// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool check(int arr[],int n,int m,int length){
        int s=0,i=0;
        while(i<n){
            if(arr[i]>length)
                return false;
            int sum = 0;
            while(sum+arr[i]<=length){
                sum += arr[i++];
            }
            s++; 
        }
        if(s<=m)
          return true;
        return false;
    }
    
    int findPages(int arr[], int n, int m) 
    {
        //code here
        int sum=0,max1=INT_MIN,res=INT_MAX;
        if(m>n)
          return -1;
        for(auto i=0;i<n;i++){
            sum += arr[i];
            max1 = max(max1,arr[i]);
        }
        int l=max1,r=sum;
        while(l<=r){
            int mid = (l+r)/2;
            if(check(arr,n,m,mid)){
                res = mid;
                r = mid-1;
            }
            else
                l = mid+1;
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends