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
#define vp vector <pair<ll,ll>>
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
vl c;

// bool compare(const &v1, const &v2) {
//   if(c[v1-1]==c[v2-1])
//     return v1>v2;
//   return c[v1-1]<c[v2-1];
// }

double find_distance(pair <double, double> p1, pair <double, double> p2) {
  return sqrt(sq(p2.first - p1.first) + sq(p2.second - p1.second));
}

vl visited;

void dfs(vector <vl> graph,ll v){
  visited[v] = 1;
  for(auto i=0;i<graph[v].size();i++){
    if(!visited[graph[v][i]])
      dfs(graph,graph[v][i]);
  }
}

vector <ll> factors2(ll n){
  vector <ll> v;
  for(ll i=2;i<=pow(2,32);i*=2){
    if(n%i==0)
      v.push_back(i);
    else
      break;
  }
  return v;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
   ll t;
   cin >> t;
   while(t--){ 
     ll n;
     cin >> n;
     vector <ll> v;
     vin(v,n);
     map <ll,ll> mp;
     for(auto i=0;i<n;i++)
        mp[v[i]]++;
     map <ll,ll> ans1;
     ans1[mp.begin()->first] = mp.begin()->second>=mp.begin()->first ? mp.begin()->first : mp.begin()->second;
     ll last = ans1[mp.begin()->first];
     for(auto i=mp.begin()+1;i!=mp.end();i++){
        ans1[i->first] = i->first-last;
        last = ans1[i->first];
     }
     for(auto i=0;i<n;i++){
        if(ans1[v[i]]==0)
          cout << v[i] << ' ';
        else{
          cout << v[i]-ans[v[i]] << ' ';
          ans[v[i]]--;
        }
     }
     cout << endl;
   }
  return 0;
}






