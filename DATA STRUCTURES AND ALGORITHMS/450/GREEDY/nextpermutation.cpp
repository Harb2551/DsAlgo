// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int ma = INT_MIN;
        int max_index = -1;
        int flag = 0;
        for(auto i=N-1;i>=0;i--){
            if(ma<arr[i]){
                ma = max(ma,arr[i]);
                max_index = i;
            }
            if(max_index!=i){
                int j;
                for(j=N-1;j>i;j--){
                    if(arr[j]>arr[i]){
                        break;
                    }
                }
                swap(arr[i],arr[j]);
                reverse(arr.begin()+i+1,arr.end());
                flag = 1;
                break;
            }
        }
        if(!flag)
            reverse(arr.begin(),arr.end());
        return arr;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends