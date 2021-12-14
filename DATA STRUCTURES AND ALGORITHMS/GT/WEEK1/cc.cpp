#include <bits/stdc++.h>
using namespace std;

struct graph{
	int v;
	struct graph *next;
};

int visited[5000];
int cc;

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

void explore(struct graph graph[],int v){
   visited[v] = 1;
   struct graph *cur;
   cur = graph[v].next;
   while(cur != NULL){
      if(!visited[cur->v]){
        explore(graph,cur->v);
      }
      cur = cur->next;
   }
}

void DFS(struct graph graph[],int n){
   cc = 0;
   for(int i=1;i<=n;i++){
      if (!visited[i]){
        cc++;         
        explore(graph,graph[i].v);
      }
   }
}

int main(){
   int n,m,x,y;
   cin >> n >> m;
   struct graph graph[n+1];
   visited.resize(n);
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
   DFS(graph,n);
   cout << cc;
}