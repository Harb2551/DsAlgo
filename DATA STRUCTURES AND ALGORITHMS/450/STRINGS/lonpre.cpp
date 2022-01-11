// { Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	    int n = s.length();
	    vector <int> v(n,0);
	    for(auto i=1;i<n;i++){
	        int j = v[i-1];
	        while(j>0 and s[i]!=s[j])
	            j = v[j-1];
	        if(s[i]==s[j])
	            j++;
	        v[i] = j;
	    }
	    return v[n-1];
	}
};

// { Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends