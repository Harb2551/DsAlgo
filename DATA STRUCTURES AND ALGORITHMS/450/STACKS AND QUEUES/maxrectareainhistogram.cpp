// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        long long ans=INT_MIN;
        stack <int> s;
        s.push(0);
        long long i;
        for(i=1;i<n;i++){
            while(i<n and arr[i]>=arr[s.top()]){
                s.push(i);
                i++;
            }
            if(i==n)
                break;
            while(!s.empty() and arr[i]<arr[s.top()]){
                long long temp = s.top();
                s.pop();
                long long width = s.empty() ? i : i-s.top()-1;
                long long length = arr[temp];
                ans = max(width*length,ans);
            }
            s.push(i);
        }
        while(!s.empty()){
            long long temp = s.top();
            s.pop();
            long long length = arr[temp];
            long long width = s.empty() ? i : i-s.top()-1;
            ans = max(ans,length*width);
            
        }
        return ans;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends