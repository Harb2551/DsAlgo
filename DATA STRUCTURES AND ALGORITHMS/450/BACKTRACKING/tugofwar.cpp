#include <bits/stdc++.h>
using namespace std;

void solve(vector <int> &arr,int n,int i,int n1,int nf,int sum,int &tempsum,int &ans){
	if(n1==nf){
		ans = min(ans,abs(sum-tempsum-tempsum));
		return;
	}
	if(i==n)
		return;
	solve(arr,n,i+1,n1,nf,sum,tempsum,ans);
	tempsum += arr[i];
	solve(arr,n,i+1,n1+1,nf,sum,tempsum,ans);
	tempsum -= arr[i];
}

int tugOfWar(vector<int> &arr, int n)
{
    // write your code here
    int sum = 0;
    sum = accumulate(arr.begin(),arr.end(),0);
    int tempsum = 0,ans=INT_MAX;
    int nf = (n&1) ? (n-1)/2 : n/2;
    solve(arr,n,0,0,nf,sum,tempsum,ans);
    return ans;
}