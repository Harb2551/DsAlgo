// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/

int maxChainLen(struct val p[],int n)
{
    //Your code here
    sort(p,p+n,compare);
    int dp[n];
    memset(dp,0,sizeof(dp));
    for(auto i=1;i<n;i++){
        for(auto j=0;j<i;j++){
            if(p[i].first>p[j].second && dp[i]<dp[j]+1)
                dp[i] = dp[j]+1;
        }
    }
    return *max_element(dp,dp+n)+1;
}