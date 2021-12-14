#include <bits/stdc++.h>
using namespace std;

struct graph{
   int v;
   struct graph *next;
};

vector <int> color;

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

// int BFS(struct graph graph[],int s,int n){
//    vector <int> queue;
//    int front = 0,rear = 0;
//    queue.resize(n+1,0);
//    queue[rear++] = s;
//    color[s] = 0;
//    while(queue[front] != 0){
//       int cur = queue[front];
//       front++;
//       struct graph *temp = graph[cur].next;
//       while(temp != NULL){
//         if(color[temp->v] == -1){
//            color[temp->v] = 1 - color[cur];
//            queue[rear++] = temp->v;
//         }
//         else if(color[temp->v] == color[cur])
//             return 0;
//          temp = temp->next;
//       }
//    }
//    return 1;
// }

int explore(struct graph graph[],int v){
   struct graph *cur;
   cur = graph[v].next;
   while(cur != NULL){
     if(color[cur->v] == -1){
        color[cur->v] = 1 - color[v];
        if(!explore(graph,cur->v))
           return 0;
     }
     else if (color[cur->v] == color[v]){
         return 0;
     }
     cur = cur->next;
   }
   return 1;
}

int DFS(struct graph graph[],int n){
   for(int i=1;i<=n;i++){
      if (color[i] == -1){  
        color[i] = 0;   
        if(!explore(graph,i))
          return 0;
      }
   }
   return 1;
}


int main(){
   int n,m,x,y;
   cin >> n >> m;
   struct graph graph[n+1];
   color.resize(n+1,-1);
   for(int i=1;i<=n;i++){
       graph[i].v = i;
       graph[i].next = NULL; 
   }  
   for(int i=1;i<=m;i++){
      cin >> x >> y;
      insert_graph(graph,x,y);
      insert_graph(graph,y,x);
   }
   // int ans;
   // for(int i=1;i<=n;i++){
   //    if(color[i] == -1){
   //      ans = BFS(graph,i,n);
   //      if(!ans)
   //         break;
   //    }
   // }
   cout << DFS(graph,n);
}