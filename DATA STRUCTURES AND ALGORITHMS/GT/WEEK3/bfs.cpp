#include <bits/stdc++.h>
using namespace std;

struct graph{
   int v;
   struct graph *next;
};

vector <int> prev1;
vector <int> dist;

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

int BFS(struct graph graph[],int s,int x,int n){
   vector <int> queue;
   int front = 0,rear = 0;
   queue.resize(n+1,0);
   queue[rear++] = s;
   dist[s] = 0;
   while(queue[front] != 0){
      int cur = queue[front];
      front++;
      struct graph *temp = graph[cur].next;
      while(temp != NULL){
         if(dist[temp->v] == 1000000){
            queue[rear++] = temp->v;
            dist[temp->v] = dist[cur] + 1;
            prev1[temp->v] = cur;
         }
         temp = temp->next;
      }
   }
   return (dist[x] == 1000000) ? 0 : 1;
}

int get_path(int s,int x){
   int count = 0;
   while(x!=s){
      x = prev1[x];
      count++;
   }
   return count;
}

int main(){
   int n,m,x,y;
   cin >> n >> m;
   struct graph graph[n+1];
   prev1.resize(n+1);
   dist.resize(n+1,1000000);
   for(int i=1;i<=n;i++){
       graph[i].v = i;
       graph[i].next = NULL; 
   }  
   for(int i=1;i<=m;i++){
      cin >> x >> y;
      insert_graph(graph,x,y);
      insert_graph(graph,y,x);
   }
   int s,x1;
   cin >> s >> x1;
   int c = BFS(graph,s,x1,n);
   if(c == 0)
      cout << -1;
   else{
     int count = get_path(s,x1);
     cout << count;
   }
}


