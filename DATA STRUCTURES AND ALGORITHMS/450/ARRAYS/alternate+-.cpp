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
 
 
void swap(ll &a,ll &b){
  ll temp = a;
  a = b;
  b = temp;
}

bool prime[1000005];
vector <ll> prime_num;
 
void SieveOfEratosthenes(int n){    
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++){
        if (prime[p] == true){
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}
 
void gen_primes(ll num){
  SieveOfEratosthenes(num);
  for(auto i=2;i<=num;i++){
    if(prime[i])
      prime_num.push_back(i);
  }
}
 
ll factors(ll num,map <ll,ll> &mp,vector <ll> &v){
  ll count = 0;
  for(auto i=0;prime_num[i]*prime_num[i]<=num;i++){
    while(num%(prime_num[i])==0){
      num /= (prime_num[i]);
      count++;
      mp[prime_num[i]]++;
      v.push_back(prime_num[i]);
    }
  }
  if(num!=1){
    count++;
    mp[num]++;
    v.push_back(num);
  }
  return count;
}

bool is_prime(ll num){
  for(auto i=2;i*i<=num;i++){
    if(num%i==0)
      return false;
  }
  return true;
}
 
void all_factors(ll num,vector <ll> &v){
  ll count = 0;
  v.push_back(1);
  for(auto i=2;i*i<=num;i++){
    if(i*i == num){
      v.push_back(i);
      break;
    }
    else if(num%i==0){
      v.push_back(i);
      v.push_back(num/i);
    }
  }
  v.push_back(num);
}

bool compare(const vector <ll> &v1,const vector <ll> &v2){
  return v1[0]<v2[0];
}

int main(){ 
  ll n;
  cin >> n;
  ll a[n];
  ain(a,n);
  ll pos=0,neg=0;
  for(auto i=0;i<n;i++){
    if(i&1 && a[i]>0){
      if(i>=neg)
        neg=i+1;
      while(neg<n && a[neg]>0) neg++;
      if(neg==n)
        break;
      swap(a[i],a[neg]);
      neg++;
    }
    else if(!(i&1) && a[i]<0){
      if(i>=pos)
        pos = i+1;
      while(pos<n && a[pos]<0) pos++;
      if(pos==n)
        break;
      swap(a[i],a[pos]);
      pos++;
    }
  }
  for(auto i=0;i<n;i++)
    cout << a[i] << ' ';
  cout << endl;
  return 0;
}