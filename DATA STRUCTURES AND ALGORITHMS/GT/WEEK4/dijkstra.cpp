#include <bits/stdc++.h>
using namespace std;


struct graph{
	int v;
  int e;
	struct graph *next;
};

vector <long long int> cost;
vector <int> done;
vector <int> q;

void swap(int *a,int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int left_child(int i){
   return (2*i+1);
}

int right_child(int i){
   return (2*i+2);
}

int parent(int i){
   return (i-1)/2;
}

void shift_down(int i){
   int min_index = i;
   if ((left_child(i)<q.size()) && (cost[q[min_index]] > cost[q[left_child(i)]])){
      min_index = left_child(i);
   }
   if ((right_child(i) < q.size()) && (cost[q[min_index]] > cost[q[right_child(i)]])){
      min_index = right_child(i);
   }
   if (min_index != i){
      swap(&q[min_index],&q[i]);
      shift_down(min_index);
   }
}

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

int extract_min(){
   int temp = q[0];
   swap(&q[0],&q[q.size()-1]);
   q.pop_back();
   shift_down(0);
   return temp;
}

void shift_up(int i){
   if(i>0 && cost[q[i]] < cost[q[parent(i)]]){
      swap(&q[i],&q[parent(i)]);
      i = parent(i);
      shift_up(i);
   }
}

void dijkstra(struct graph graph[],int u){
   q.push_back(u);
   cost[u] = 0;
   while(!q.empty()){
      int cur = extract_min();
      while(done[cur]!=0){
         if(q.empty())
            break;
         cur = extract_min();
      }
      if(done[cur]==1)
         break;
      done[cur] = 1;
      struct graph *temp;
      temp = graph[cur].next;
      while(temp!=NULL){
         if(cost[temp->v] > cost[cur] + temp->e){
            cost[temp->v] = cost[cur] + temp->e;
            q.push_back(temp->v);
            shift_up(q.size()-1);
         }
         temp = temp->next;
      }
   }
}

int main(){
   int n,m,x,y,e,u,v;
   cin >> n >> m;
   struct graph graph[n+1];
   cost.resize(n+1);
   done.resize(n+1);
   for(int i = 1;i<=n;i++){
       graph[i].v = i;
       graph[i].next = NULL; 
       cost[i] = 10000000000;
       done[i] = 0;
   }  
   for(int i = 1;i<=m;i++){
      cin >> x >> y >> e;
      insert_graph(graph,x,y,e);
   }
   cin >> u >> v;
   dijkstra(graph,u);
   if(cost[v] == 10000000000)
     cout << -1;
   else
     cout << cost[v];
}