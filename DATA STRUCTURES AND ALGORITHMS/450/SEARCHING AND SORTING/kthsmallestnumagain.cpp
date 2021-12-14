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

bool compare(const pair<ll,ll> &v1,const pair <ll,ll> &v2) {
    if(v1.first==v2.first)
      return v1.second>v2.second;
    return v1.first<v2.first;
}

double find_distance(pair <double, double> p1, pair <double, double> p2) {
  return sqrt(sq(p2.first - p1.first) + sq(p2.second - p1.second));
}

int main() {
  ll t;
  cin >> t;
  while(t--){
    ll n,q;
    cin >> n >> q;
    std::vector <pair<ll,ll>> v;
    while(n--){
      ll a,b;
      cin >> a >> b;
      v.pb({a,b});
    }
    sortc(v,compare);
    ll last  = v[0].second;
    for(auto i=v.begin()+1;i!=v.end();i++){
      if(i->first<=last && i->second > last){
        i->first = last + 1;
        last = i->second;
      }
      else if(i->first<=last)
         i->first = LLONG_MAX;
      else
         last = i->second;
    }
    vl ans;
    vector <pair<ll,ll>> v1;
    for(auto i=v.begin();i!=v.end();i++){
       if(i->first != LLONG_MAX){
          v1.pb(*i);
       }
    }
    ans.pb(v1[0].second-v1[0].first + 1);
    for(auto i=1;i<v1.size();i++){
       ans.pb(ans[i-1]+v1[i].second-v1[i].first + 1);
    }
    while(q--){
      ll k;
      cin >> k;
      auto ub = upper_bound(ans.begin(),ans.end(),k);
      if(ub==ans.end() && *(ub-1)!=k)
        cout << -1 << endl;
      else{
        if(ub==ans.begin()){
           ll index = 0;
           cout << v1[index].first+k-1 << endl;
        }
        else{
          if(*(ub-1)==k){
            ll index = ub - ans.begin()-1;
            cout << v1[index].second << endl;
          }
          else{
            ll index = ub-ans.begin();
            ll z = k-*(ub-1);
            cout << v1[index].first+z-1 << endl;
          }
        }
      }
    }
  }
  return 0;
}