#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define intmax INT_MAX
#define intmin INT_MIN
#define ain(a,n) for(auto i=0;i<n;i++){cin >> a[i];}
#define ain2(a,n,m) for(auto i=0;i<n;i++){for(auto j=0;j<m;i++){cin >> a[i][j];}}
#define aout(a,n) for(auto i=0;i<n;i++){cout << a[i] << ' ';}
#define aout2(a,n,m) for(auto i=0;i<n;i++){for(auto j=0;j<m;i++){cout << a[i][j] << ' ';}cout << endl;}
#define vin(v,n) for(auto i=0;i<n;i++){ll x; cin >> x; v.push_back(x);}
#define vin2(v,n,m) for(auto i=0;i<n;i++){vl v1; vin(v1,m); v.pb(v1);}
#define vout(v) for(auto i=v.begin();i!=v.end();i++){cout << *i << ' ';} cout << endl;
#define vout2(v) for(auto j=0;j<v.size();j++){vout(v[j]);}
#define sortc(v,c) sort(v.begin(),v.end(),c)
#define sorte(v) sort(v.begin(),v.end())
#define pb push_back
#define vl vector <ll>
#define vs vector <string>
#define vd vector <double>
#define vvl vector <vl>
#define vvs vector <vs>
#define vvd vector <vd>
#define sq(x) ((x) * (x))
using namespace std;

bool prime[1000005];
vector <ll> prime_num;

void SieveOfEratosthenes(int n) {
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p)
        prime[i] = false;
    }
  }
}

void gen_primes(ll num) {
  SieveOfEratosthenes(num);
  for (auto i = 2; i <= num; i++) {
    if (prime[i])
      prime_num.push_back(i);
  }
}

ll factors(ll num, map <ll, ll> &mp, vector <ll> &v) {
  ll count = 0;
  for (auto i = 0; prime_num[i]*prime_num[i] <= num; i++) {
    while (num % (prime_num[i]) == 0) {
      num /= (prime_num[i]);
      count++;
      mp[prime_num[i]]++;
      v.push_back(prime_num[i]);
    }
  }
  if (num != 1) {
    count++;
    mp[num]++;
    v.push_back(num);
  }
  return count;
}

bool is_prime(ll num) {
  for (auto i = 2; i * i <= num; i++) {
    if (num % i == 0)
      return false;
  }
  return true;
}

void all_factors(ll num, vector <ll> &v) {
  ll count = 0;
  v.push_back(1);
  for (auto i = 2; i * i <= num; i++) {
    if (i * i == num) {
      v.push_back(i);
      break;
    }
    else if (num % i == 0) {
      v.push_back(i);
      v.push_back(num / i);
    }
  }
  v.push_back(num);
}

bool compare(const vector <ll> &v1, const vector <ll> &v2) {
  return v1[0] < v2[0];
}

double find_distance(pair <double, double> p1, pair <double, double> p2) {
  return sqrt(sq(p2.first - p1.first) + sq(p2.second - p1.second));
}

double compute_hash(vvl t){
  double sum=0;
  ll prod = 1;
  for(auto i=0;i<t.size();i++){
    for(auto j=t[i].begin();j!=t[i].end();j++){
      sum += *j * (i+1) * (j-t[i].begin()+1);
      prod *= *j/((i*(j-t[i].begin())+1));
      prod %= mod;
    }
  }
  double ans = prod-sum;
  return ans;
}

bool search(vvl v,vvl w,ll n,ll m,ll x,ll y,ll length){
  vd ans;
  for(auto i=0;i+length-1<n;i++){
    for(auto j=0;j+length-1<n;j++){
      vvl t;
      for(auto k=i;k<i+length;k++){
        vl s;
        for(auto l=j;l<j+length;l++){
          s.pb(v[k][l]);
        }
        t.pb(s);
      }
      ans.pb(compute_hash(t));
    }
  }
  for(auto i=0;i+length-1<x;i++){
    for(auto j=0;j+length-1<y;j++){
      vvl t;
      for(auto k=i;k<i+length;k++){
        vl s;
        for(auto l=j;l<j+length;l++){
          s.pb(v[k][l]);
        }
        t.pb(s);
      }
      auto a =compute_hash(t);
      auto b = lower_bound(ans.begin(),ans.end(),a);
      if(b!=ans.end() && *b==a)
        return true;
    }
  }
  return false;
}

ll solve(vvl v,vvl w,ll n,ll m,ll x,ll y){
  ll l=0,r = min(min(n,m),min(x,y)),ans=intmin;
  while(l<=r){
    ll mid = (l+r)/2;
    if(search(v,w,n,m,x,y,mid)){
      l = mid+1;
      ans = max(ans,mid);
    }
    else{
      r = mid-1;
    }
  }
  return ans;
}

int main() {
  ll n,m;
  cin >> n >> m;
  vvl v;
  vin2(v,n,m);
  ll x,y;
  cin >> x >> y;
  vvl w;
  vin2(w,x,y);
  ll ans = solve(v,w,n,m,x,y);
  cout << ans << endl;
  return 0;
}