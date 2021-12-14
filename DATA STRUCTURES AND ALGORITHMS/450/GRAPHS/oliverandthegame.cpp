#include <bits/stdc++.h> 
using namespace std;

vector <int> preorder;
vector <int> postorder;
vector <int> visited;
int pre=1;

void dfs(vector <int> graph[],int v){
	visited[v] = 1;
	preorder[v] = pre++;
	int n = graph[v].size();
	for(auto i=0;i<n;i++){
		if(!visited[graph[v][i]])
			dfs(graph,graph[v][i]);
	}
	postorder[v] = pre++;
}

int main(){
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	int n;
	cin >> n;
	pre = 1;
	vector <int> graph[n+1];
	postorder.resize(n+1);
	preorder.resize(n+1);
	visited.resize(n+1,0);
	for(auto i=0;i<n-1;i++){
		int x,y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs(graph,1);
	int q;
	cin >> q;
	while(q--){
		int a,b,c;
		cin >> a >> b >> c;
		if(a){
			if(preorder[c]<preorder[b] and postorder[c]>postorder[b])
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else{
			if(preorder[c]>preorder[b] and postorder[c]<postorder[b])
				cout << "YES" << endl;
			else	
				cout << "NO" << endl;
		}
	}
}










