#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

ll isValid(ll a[],ll length,ll cows,ll n){
	ll c=1,cur = a[0];
	for(auto i=1;i<n;i++){
		if(a[i]-cur>=length){
			cur = a[i];
			c++;
		}
	}
	if(c>=cows)
		return 1;
	return 0;
}

ll solve_with_bs(ll a[], ll n, ll cows){
 	ll l=1,r=a[n-1]-a[0];
 	ll ans = 0;
 	while(l<=r){
 		ll mid = (l+r)/2;
 		if(isValid(a,mid,cows,n)){
 		   ans = max(ans,mid);
 		   l = mid+1;
 		}
 		else{
 			r = mid-1;
 		}
 	}
 	return ans;
}

int main()
{
 ll t;
 cin >> t;
 while(t--){
  ll n,cows;
  cin >> n >> cows;
  ll a[n];
  for(auto i=0;i<n;i++)
  	cin >> a[i];
  sort(a,a+n);
  ll ans = solve_with_bs(a,n,cows);
  cout << ans << endl;
 }
  return 0;
}
