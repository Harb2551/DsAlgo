// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        // Your code goes here
        sort(arr,arr+N,greater<int>());
        int sum = 0;
        int i=0;
        while(i<N-1){
            while(i<N-1 && abs(arr[i]-arr[i+1])>=K)
                i++;
            if(i==N-1)
                break;
            sum += arr[i]+arr[i+1];
            i+=2;
        }
        return sum;
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}
  // } Driver Code Ends