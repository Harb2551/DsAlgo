// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:

    int sb(int arr[], int n, int x)
    {
        // Your code goes here  
        int i=0,j=0,sum=0,ans=INT_MAX;
        while(i<n){
            while(sum<=x && j<n){
                sum += arr[j++];
            }
            if(j-i<ans && sum>x)
                ans = j-i;
            sum -= arr[i++];
            if(j==n && sum<=x){
                break;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.sb(a,n,x)<<endl;
	}
	return 0;
}  // } Driver Code Ends