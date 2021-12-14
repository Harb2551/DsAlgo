#include <bits/stdc++.h>
using namespace std;

struct graph{
	int v;
	struct graph *next;
};

vector <int> visited;
vector <int> previsit;
vector <int> postvisit;
vector <int> pv;
int count1 = 0;

void previsit1(int v){
   count1++;
   previsit[v] = count1;
}

void postvisit1(int v){
	count1++;
	postvisit[v] = count1;
    pv.push_back(v);
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

void explore(struct graph graph[],int v){
   visited[v] = 1;
   struct graph *cur;
   cur = graph[v].next;
   previsit1(v);
   while(cur != NULL){
   	 if(!visited[cur->v])
       explore(graph,cur->v);
     cur = cur->next;
   }
   postvisit1(v);
}

void DFS(struct graph graph[],int n){
   for(int i=1;i<=n;i++){
      if (!visited[i]){     
        explore(graph,graph[i].v);
      }
   }
}

int main(){
   int n,m,x,y;
   cin >> n >> m;
   struct graph graph[n+1];
   visited.resize(n+1);
   previsit.resize(n+1);
   postvisit.resize(n+1);
   for(int i = 1;i<=n;i++){
       graph[i].v = i;
       graph[i].next = NULL; 
       visited[i] = 0;
   }  
   for(int i = 1;i<=m;i++){
      cin >> x >> y;
      insert_graph(graph,x,y);
   }
   DFS(graph,n);
   for(int i = pv.size()-1;i>=0;i--){
   	  cout << pv[i] << " ";
   }
}