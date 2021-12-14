// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // coode here 
         map <int,int> mp;
        for(auto i=0;i<n;i++){
            mp[a[i]]++;
        }
        int j=0;
        for(auto i=0;i<3;i++){
            while(mp[i]--){
                a[j++] = i;
            }
        }
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends