// { Driver Code Starts
// Initial function Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    
    long int disarrange(int N){
        // code here
        int mod = 1000000007;
        if(N==2 || N==1)
            return N-1;
        long long a=0,b=1,ans;
        for(auto i=3;i<=N;i++){
            int temp = b;
            b = ((i-1)*(a+b)%mod)%mod;
            a = temp;
        }
        return b;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.disarrange(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends