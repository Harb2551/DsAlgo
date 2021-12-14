#include <bits/stdc++.h>
using namespace std;

struct graph{
	int v;
	struct graph *next;
};

int visited[5000];

int search(int v,vector <int> v1){
   for(int i:v1){
      if(i == v)
         return 1;
   }
   return 0;
}

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

int explore(struct graph graph[],int v,vector<int> v1){
   visited[v] = 1;
   if(search(v,v1))
      return 1;
   v1.push_back(v);
   struct graph *cur;
   cur = graph[v].next;
   while(cur != NULL){
      int ans = explore(graph,cur->v,v1);
      if(ans)
         return 1;
      cur = cur->next;
   }
   return 0;
}

int DFS(struct graph graph[],int n){
   for(int i=1;i<=n;i++){
      if (!visited[i]){    
        vector<int> exp_visit;    
        int ans = explore(graph,graph[i].v,exp_visit);
        if(ans)
         return 1;
      }
   }
   return 0;
}

int main(){
   int n,m,x,y;
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
   }
   cout << DFS(graph,n);
}