// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n){
        // Your code here
        int maxsum=0,sum=0,neg=0;
        for(auto i=0;i<n;i++){
            if(arr[i]<0)
              neg++;
        }
        if(neg==n){
            int max = INT_MIN;
            for(auto i=0;i<n;i++){
                if(arr[i]>max)
                    max = arr[i];
            }
            return max;
        }
        for(auto i=0;i<n;i++){
            if(sum+arr[i]<0){
                if(sum>maxsum)
                    maxsum = sum;
                sum = 0;
            }
            else{
                if(sum>maxsum)
                    maxsum = sum;
                sum += arr[i];
            }
        }
        if(maxsum<sum)
            maxsum = sum;
        return maxsum;
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends