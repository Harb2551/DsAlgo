// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	    vector <int> v;
	    int count=0;
	    for(auto i:S){
	        if(i=='1'){
	            v.push_back(-1);
	            count++;
	        }
	        else
	            v.push_back(1);
	    }
	    int max_sum=0,sum=0,n=v.size();
	    for(auto i=0;i<n;i++){
	        if(sum+v[i]>max_sum)
	            max_sum = sum+v[i];
	        if(sum+v[i]<=0)
	            sum=0;
	        else
	            sum += v[i];
	    }
	    return count==n ? -1 : max_sum;
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
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends