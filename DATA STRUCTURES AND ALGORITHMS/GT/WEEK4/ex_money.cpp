#include <bits/stdc++.h>
using namespace std;

struct graph{
	int v;
  long long int e;
	struct graph *next;
};

vector <long long int> cost;
vector <int> nc;
vector <int> dist;
vector <int> visited2;

void insert_graph(struct graph graph[],int x,int y,long long int e){
   struct graph *temp,*cur;
   temp = (struct graph*)malloc(sizeof(struct graph));
   temp->v = y;
   temp->next = NULL;
   temp->e = e;
   cur = &graph[x];
   while(cur->next != NULL){
      cur = cur->next;
   }
   cur->next = temp;
}

void bellman_ford(struct graph graph[],int u,int n){
    queue <int> q;
    queue <int> q2;
    cost[u] = 0;
    for(int i = 1;i<=2*n;i++){
      q.push(u);
      vector <int> visited;
      visited.resize(n+1,0);
      while(!q.empty()){
        int cur = q.front();
        q.pop();
        visited[cur] = 1;
    		struct graph *temp;
    		temp = graph[cur].next;
    		while(temp!=NULL){
       //    cout <<"i=" <<j<< " j="<<temp->v<< "temp->v=" << cost[temp->v] << " cost[graph[j].v] + temp->e = " << cost[graph[j].v] + temp->e << endl;
    			if(!visited[temp->v]){
             q.push(temp->v);
             visited[temp->v] = 1;
          }
          if(cost[temp->v] > cost[graph[cur].v] + temp->e){
            // cout << "j=" << j << " temp->v=" << temp->v << "cost[4]= " << cost[4] << endl;
    				if(i==2*n){
    					q2.push(temp->v);
            }
    				cost[temp->v] = cost[graph[cur].v] + temp->e;
    			}
    			temp = temp->next;
    		}
    	}
    }
    
    visited2.resize(n+1,0);
    while (!q2.empty()){
       int p = q2.front();
       q2.pop();
       visited2[p] = 1;
       struct graph *t;
       t = graph[p].next;
       while(t!=NULL){
          if(!visited2[t->v]){
             q2.push(t->v);
             visited2[t->v] = 1;
          }
          t = t->next;
       }
    }
}

int main(){
   int n,m,x,y,u;
   long long int e;
   cin >> n >> m;
   struct graph graph[n+1];
   cost.resize(n+1);
   nc.resize(n+1,0);
   for(int i = 1;i<=n;i++){
       graph[i].v = i;
       graph[i].next = NULL; 
       cost[i] = 1000000000000000;
   }  
   for(int i = 1;i<=m;i++){
      cin >> x >> y >> e;
      insert_graph(graph,x,y,e);
   }
   cin >> u;
   bellman_ford(graph,u,n);
   for(int i=1;i<=n;i++){
     if(cost[i] == 1000000000000000)
       cout << '*' << endl;
     else if(visited2[i] == 1)
       cout << '-' << endl;
     else
       cout << cost[i] << endl;
   }
}