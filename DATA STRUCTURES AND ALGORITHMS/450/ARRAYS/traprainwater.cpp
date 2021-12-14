// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        // Code here
        int i=0,j=n-1,leftmax=arr[0],rightmax=arr[n-1],ans = 0;
        while(i<j){
            if(arr[i]<=arr[j]){
                if(arr[i]>=leftmax)
                    leftmax = arr[i];
                else
                    ans += leftmax - arr[i];
                i++;
            }
            else{
                if(arr[j]>=rightmax)
                    rightmax = arr[j];
                else
                    ans += rightmax - arr[j];
                j--;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends