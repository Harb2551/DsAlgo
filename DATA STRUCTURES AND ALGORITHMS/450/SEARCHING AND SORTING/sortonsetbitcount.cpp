// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
   int countBits(int a)
    {
        int count = 0;
        while (a) {
            if (a & 1)
                count += 1;
            a = a >> 1;
        }   
        return count;
    }
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        map <int,vector <int>> mp;
        for(auto i=0;i<n;i++){
            int count1;
            count1 = countBits(arr[i]);
            mp[count1].push_back(arr[i]);
        }
        int k=0;
        for(auto i=32;i>=0;i--){
            if(mp[i].empty())
                continue;
            for(auto j=mp[i].begin();j!=mp[i].end();j++){
                arr[k++] = *j;
            }
        }
    }
    

};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n]; 
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends