#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define ain(a,n) for(auto i=0;i<n;i++){cin >> a[i];}
#define ain2(a,n,m) for(auto i=0;i<n;i++){for(auto j=0;j<m;i++){cin >> a[i][j];}}
#define aout(a,n) for(auto i=0;i<n;i++){cout << a[i] << ' ';}
#define aout2(a,n,m) for(auto i=0;i<n;i++){for(auto j=0;j<m;i++){cout << a[i][j] << ' ';}cout << endl;}
#define vin(v,n) for(auto i=0;i<n;i++){int x; cin >> x; v.push_back(x);}
#define vout(v) for(auto i=v.begin();i!=v.end();i++){cout << *i << ' ';} cout << endl;
#define vout2(v) for(auto j=0;j<v.size();j++){vout(v[j]);}
#define sortc(v,c) sort(v.begin(),v.end(),c)
#define sorte(v) sort(v.begin(),v.end())
using namespace std;


void swap(ll &a, ll &b) {
  ll temp = a;
  a = b;
  b = temp;
}

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

double median(vector <int> nums, int i, int j) {
  int n = nums.size();
  double m1;
  if (n & 1) {
    m1 = nums[(i + j) / 2];
  }
  else {
    m1 = (nums[(i + j) / 2] + nums[(i + j) / 2 + 1]) / 2.0;
  }
  return m1;
}

double find_median(vector <int> nums1, vector <int> nums2, int i1, int j1, int i2, int j2) {
  if (j1 - i1 + 1 + j2 - i2 + 1 == 4) {
    return (max(nums1[i1 + 0], nums2[i2 + 0]) + min(nums1[i1 + 1], nums2[i2 + 1])) / 2.0;
  }
  double m1 = median(nums1, i1, j1);
  double m2 = median(nums2, i2, j2), ans;
  ll n = (j1 - i1 + 1 + j2 - i2 + 1) / 2;
  if (n & 1) {
    if (m1 == m2)
      return m1;
    else if (m1 > m2) {
      ans = find_median(nums1, nums2, i1 + 0, i1 + n / 2, i2 + n / 2, i2 + n - 1);
    }
    else {
      ans = find_median(nums1, nums2, i1 + n / 2, i1 + n - 1, i2 + 0, i2 + n / 2);
    }
  }
  else {
    if (m1 == m2)
      return m1;
    if (m1 > m2) {
      ans = find_median(nums1, nums2, i1 + 0, i1 + n / 2 - 1, i2 + n / 2, i2 + n - 1);
    }
    else {
      ans = find_median(nums1, nums2, i1 + n / 2, i1 + n - 1, i2 + 0, i2 + n / 2 - 1);
    }
  }
  return ans;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  int n = nums1.size();
  if (n == 1)
    return (nums1[0] + nums2[0]) / 2.0;
  if (n == 2)
    return (max(nums1[0], nums2[0]) + min(nums1[1], nums2[1])) / 2.0;
  return find_median(nums1, nums2, 0, n - 1, 0, n - 1);
}

int main() {
  ll n;
  cin >> n;
  vector <int> v1, v2;
  vin(v1, n);
  vin(v2, n);
  cout << findMedianSortedArrays(v1, v2) << endl;
  return 0;
}