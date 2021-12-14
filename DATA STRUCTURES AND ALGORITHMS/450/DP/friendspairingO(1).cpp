// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int mod = 1000000007;
    
    int countFriendsPairings(int n) 
    {  
        // code here
        if(n<=2)
         return n;
        int a = 1;
        int b = 2;
        for(long long i=3;i<=n;i++){
            int temp;
            temp = (b+((i-1)*a)%mod)%mod;
            a = b;
            b = temp;
        }
        return b;
    }
    
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends