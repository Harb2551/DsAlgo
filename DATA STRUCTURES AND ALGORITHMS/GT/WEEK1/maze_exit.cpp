#include <bits/stdc++.h>
using namespace std;

struct graph{
	int v;
	struct graph *next;
};

int visited[5000];

void insert_graph(struct graph graph[],int x,int y){
   struct graph *temp,*cur;
   temp = (struct graph*)malloc(sizeof(struct graph));
   temp->v = y;
   temp->next = NULL;
   cur = &graph[x];
   while(cur->next != NULL){
      cur = cur->next;
   }
   cur->next = temp;
}

int explore_check(int u,int v,struct graph graph[]){
	visited[u] = 1;
	if(u == v)
		return 1;
	struct graph *cur;
	cur = graph[u].next;
	while(cur != NULL){
		if(!visited[cur->v]){
		  int ans = explore_check(cur->v,v,graph);
		  if(ans)
		  return 1;
	    }
		cur = cur->next;
	}
	return 0;
}

int main(){
	int n,m,u,v,x,y;
	cin >> n >> m;
	struct graph graph[n+1];
	for(int i = 1;i<=n;i++){
       graph[i].v = i;
       graph[i].next = NULL; 
       visited[i] = 0;  
	}
    for(int i = 1;i<=m;i++){
		cin >> x >> y;
		insert_graph(graph,x,y);
		insert_graph(graph,y,x);
	}
    cin >> u >> v;
    cout << explore_check(u,v,graph);
}




