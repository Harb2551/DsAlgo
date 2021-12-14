#include <bits/stdc++.h>
using namespace std;

struct graph{
	int v;
    int e;
	struct graph *next;
};

vector <long long int> cost;

void insert_graph(struct graph graph[],int x,int y,int e){
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

int bellman_ford(struct graph graph[],int u,int n){
    cost[u] = 0;
    for(int i = 1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		struct graph *temp;
    		temp = graph[j].next;
    		while(temp!=NULL){
    			if(cost[temp->v] > cost[graph[j].v] + temp->e){
    				if(i==n)
    					return 1;
    				cost[temp->v] = cost[graph[j].v] + temp->e;
    			}
    			temp = temp->next;
    		}
    	}
    }
    return 0;
}

int main(){
   int n,m,x,y,e;
   cin >> n >> m;
   struct graph graph[n+1];
   cost.resize(n+1);
   for(int i = 1;i<=n;i++){
       graph[i].v = i;
       graph[i].next = NULL; 
       cost[i] = 10000000000;
   }  
   for(int i = 1;i<=m;i++){
      cin >> x >> y >> e;
      insert_graph(graph,x,y,e);
   }
   cout << bellman_ford(graph,1,n);
}