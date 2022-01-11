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

void swap(ll *a,ll *b){
   ll temp = *a;
  *a = *b;
  *b = temp;
}

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

ll size(ll num){
	int size = 0,temp=num;
	while(temp!=0){
		size++;
		temp /= 10;
	}
	return size;
}

bool compare(const pair<ll,ll> &v1,const pair<ll,ll> &v2){
	return v1.second<v2.second;
}

ll air[1500][1500];
ll water[1500][1500];
ll fire[1500][1500];

ll solve(char x,ll h,ll a){
	if(h<=0 or a<=0){
		return -1;
	}
	ll ans1,ans2;
	if(x=='a'){
		if(air[h][a]!=-1)
			return air[h][a];
		ans1 = 1+solve('f',h+3,a+2);
		ans2 = 1+solve('w',h+3,a+2);
		return air[h][a] = max(ans1,ans2);
	}
	else if(x=='w'){
		if(water[h][a]!=-1)
			return water[h][a];
		ans1 = 1+solve('a',h-5,a-10);
		ans2 = 1+solve('f',h-5,a-10);
		return water[h][a] = max(ans1,ans2);
	}
	else{
		if(fire[h][a]!=-1)
			return fire[h][a];
		ans1 = 1+solve('a',h-20,a+5);
		ans2 = 1+solve('w',h-20,a+5);
		return fire[h][a] = max(ans1,ans2);
	}
	return max(ans1,ans2);
}

int main() {
	ll t;
	cin >> t;
	while(t--){
	   ll h,a;
	   cin >> h >> a;
	   memset(air,-1,sizeof(air));
	   memset(water,-1,sizeof(water));
	   memset(fire,-1,sizeof(water));
	   ll ans1 = solve('a',h,a);
	   ll ans2 = solve('w',h,a);
	   ll ans3 = solve('f',h,a);
	   cout << max(ans1,max(ans2,ans3)) << endl;
	}
	return 0;
}















