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

bool compare(const pair<ll, ll> &v1, const pair <ll, ll> &v2) {
  if (v1.first == v2.first)
    return v1.second > v2.second;
  return v1.first < v2.first;
}

double find_distance(pair <double, double> p1, pair <double, double> p2) {
  return sqrt(sq(p2.first - p1.first) + sq(p2.second - p1.second));
}

void gen_subset_sum(vl v,vl &sum,ll i,ll n){
   ll range = n-i;
   for(auto j=0;j<1<<range;j++){
      ll sum1=0;
      ll p=0,num=j;
      while(num){
        if(num&1) sum1+=v[p];
        p++;
        num >>= 1;
      }
      sum.pb(sum1);
   }
}

int main(){
  ll n,a,b;
  cin >> n >> a >> b;
  vl v1,v2;
  vin(v1,n/2);
  vin(v2,n-n/2);
  vl sum1,sum2;
  gen_subset_sum(v1,sum1,0,n/2);
  gen_subset_sum(v2,sum2,n/2,n);
  sorte(sum2);
  ll ans = 0;
  for(auto i=0;i<sum1.size();i++){
    ll y = a-sum1[i];
    ll z = b-sum1[i];
    auto p = lower_bound(sum2.begin(),sum2.end(),y);
    auto q = upper_bound(sum2.begin(),sum2.end(),z);
    ll i1 = p - sum2.begin();
    ll i2 = q - sum2.begin();
    ans += i2-i1;
  }
  cout << ans << endl;
}