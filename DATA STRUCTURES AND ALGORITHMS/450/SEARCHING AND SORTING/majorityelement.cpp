// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        // your code here
        int ele=-1,ef=1,n=size;
    for(auto i=0;i<n;i++){
        if(a[i]!=ele)
            ef--;
        else
            ef++;
        if(ef==0){
            ele = a[i];
            ef++;
        }
    }
    ef=0;
    for(auto i=0;i<n;i++){
        if(a[i]==ele)
            ef++;
    }
    if(ef>n/2)
        return ele;
    return -1;
        
    }
};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends