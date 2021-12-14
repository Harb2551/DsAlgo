#include<bits/stdc++.h>
#define ll long long int 
#define mod 1000000007
#define ain(a,n) for(auto i=0;i<n;i++){cin >> a[i];}
#define ain2(a,n,m) for(auto i=0;i<n;i++){for(auto j=0;j<m;i++){cin >> a[i][j];}}
#define aout(a,n) for(auto i=0;i<n;i++){cout << a[i] << ' ';}
#define aout2(a,n,m) for(auto i=0;i<n;i++){for(auto j=0;j<m;i++){cout << a[i][j] << ' ';}cout << endl;}
#define vin(v,n) for(auto i=0;i<n;i++){string x; cin >> x; v.push_back(x);}
#define vout(v) for(auto i=v.begin();i!=v.end();i++){cout << *i << ' ';} cout << endl;
#define vout2(v) for(auto j=0;j<v.size();j++){vout(v[j]);}
#define sortc(v,c) sort(v.begin(),v.end(),c)
#define sorte(v) sort(v.begin(),v.end())
using namespace std;
 

int min_operations(int a[],int n){
   int i=0,j=n-1,ans=0;
   while(i<=j){
   	  if(a[i]==a[j]){
   	  	i++;
   	  	j--;
   	  }
   	  else if(a[i]>a[j]){
   	  	j--;
   	  	a[j] += a[j+1];
   	  	ans++;
   	  }
   	  else{
   	  	i++;
   	  	a[i] += a[i-1];
   	  	ans++;
   	  }
   }
   return ans;
}

int main(){
	int n;
	cin >> n;
	int a[n];
	ain(a,n);
	cout << min_operations(a,n) << endl;
}