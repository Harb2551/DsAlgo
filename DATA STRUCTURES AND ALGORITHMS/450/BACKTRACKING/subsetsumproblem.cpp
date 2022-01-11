#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define ain(a,n) for(auto i=0;i<n;i++){cin >> a[i];}
#define ain2(a,n,m) for(auto i=0;i<n;i++){for(auto j=0;j<m;i++){cin >> a[i][j];}}
#define aout(a,n) for(auto i=0;i<n;i++){cout << a[i] << ' ';}
#define aout2(a,n,m) for(auto i=0;i<n;i++){for(auto j=0;j<m;i++){cout << a[i][j] << ' ';}cout << endl;}
#define vin(v,n) for(auto i=0;i<n;i++){ll x; cin >> x; v.push_back(x);}
#define vout(v) for(auto i=v.begin();i!=v.end();i++){cout << *i << ' ';} cout << endl;
#define vout2(v) for(auto j=0;j<v.size();j++){vout(v[j]);}
#define sortc(v,c) sort(v.begin(),v.end(),c)
#define sorte(v) sort(v.begin(),v.end())
using namespace std;

vector <int> previsit;
vector <int> postvisit;
vector <int> visited;

// void previsit1(int v){
//   count1++;
//   previsit[v] = count1;
// }

// void postvisit1(int v){
// 	count1++;
// 	postvisit[v] = count1;
//     pv.push_back(v);
// }

// int BFS(struct graph graph[],int s,int x,int n){
//   vector <int> queue;
//   int front = 0,rear = 0;
//   queue.resize(n+1,0);
//   queue[rear++] = s;
//   dist[s] = 0;
//   while(queue[front] != 0){
//       int cur = queue[front];
//       front++;
//       struct graph *temp = graph[cur].next;
//       while(temp != NULL){
//          if(dist[temp->v] == 1000000){
//             queue[rear++] = temp->v;
//             dist[temp->v] = dist[cur] + 1;
//             prev1[temp->v] = cur;
//          }
//          temp = temp->next;
//       }
//   }
//   return (dist[x] == 1000000) ? 0 : 1;
// }

// void explore(struct graph graph[],int v){
//   visited[v] = 1;
//   struct graph *cur;
//   cur = graph[v].next;
// //   previsit1(v);
//   while(cur != NULL){
//   	 if(!visited[cur->v])
//       explore(graph,cur->v);
//      cur = cur->next;
//   }
// //   postvisit1(v);
// }

// void DFS(struct graph graph[],int n){
//   for(int i=1;i<=n;i++){
//       if (!visited[i]){     
//         explore(graph,graph[i].v);
//       }
//   }
// }

bool prime[100005];
vector <ll> prime_num;

void SieveOfEratosthenes(int n)
{    
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
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

ll factors(ll num,map <ll,ll> &mp){
	ll count = 0;
	for(auto i=0;prime_num[i]*prime_num[i]<=num;i++){
		while(num%(prime_num[i])==0){
			num /= (prime_num[i]);
			count++;
			mp[prime_num[i]]++;
		}
	}
	if(num!=1){
		count++;
		mp[num]++;
	}
	return count;
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

long long int gcd(long long int a,long long int b){
	if (b == 0){
		return a;
	}
    long long int rem = a%b;
    return gcd(b,rem);
}

bool compare(const pair<ll,ll> &v1,const pair<ll,ll> &v2){
	return v1.second<v2.second;
}

// long long calculate(long long p,
//                     long long q)
// {
//     long long mod = 998244353, expo;
//     expo = mod - 2;
//     while (expo) {
//         if (expo & 1) {
//             p = (p * q) % mod;
//         }
//         q = (q * q) % mod;
//         expo >>= 1;
//     }
//     return p;
// }

void solve(vector <vector<ll>> &ans,vector <ll> v,ll i,ll n,ll &sum,ll target,vector <ll> &temp){
	if(sum==target){
		ans.push_back(temp);
		if(i==n)
		    return;
	}
	if(i==n or sum>target)
		return;
	ll cur = sum;
	auto v1 = temp;
	if(sum==target){
	    sum = 0;
		temp.clear();
	}
	for(auto j=i;j<n;j++){
		sum += v[j];
		temp.push_back(v[j]);
		solve(ans,v,j+1,n,sum,target,temp);
		temp.pop_back();
		sum -= v[j];
	}
	sum = cur;
	temp = v1;
}

int main(){
	ll t;
	cin >> t;
	while(t--){  
		ll n;
		cin >> n;
		vector <ll> v;
		vin(v,n);
		vector <vector<ll>> ans;
		vector <ll> temp;
		ll sum=0,target;
		cin >> target;
		solve(ans,v,0,n,sum,target,temp);
		vout2(ans);
	}
	return 0;
}















