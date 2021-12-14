// { Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

 // } Driver Code Ends
// Complete this function
long long int count(long long int n)
{
	long long int table[4][n+1],i;
	memset(table, 0, sizeof(table));
	table[0][0]=1;                // If 0 sum is required number of ways is 1.
	
	// Your code here
	long long a[] = {3,5,10};
	for(auto i=0;i<=3;i++){
	    for(auto j=0;j<=n;j++){
	        if(j==0)
	            table[i][j] = 1;
	        else if(i==0)
	            table[i][j] = 0;
	        else{
	            if(a[i-1]<=j)
	                table[i][j] = table[i-1][j] + table[i][j-a[i-1]];
	            else
	                table[i][j] = table[i-1][j];
	        }
	    }
	}
	return table[3][n];
}

// { Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends