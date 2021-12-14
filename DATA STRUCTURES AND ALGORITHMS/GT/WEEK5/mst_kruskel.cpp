#include <bits/stdc++.h>
using namespace std;

struct point{
	double x;
	double y;
};

struct edge{
	int v1;
	int v2;
	double e;
};

vector <int> parent;
vector <int> rank1;

void makeset(int i){
	parent[i] = i;
	rank1[i] = 0;
}

int find(int i){
	while(parent[i] != i){
		i = parent[i];
	}
	return i;
}

void swap(struct edge *p,struct edge *q){
  struct edge temp;
  temp.v1 = p->v1;
  temp.v2 = p->v2;
  temp.e = p->e;
  p->v1 = q->v1;
  p->v2 = q->v2;
  p->e = q->e;
  q->v1 = temp.v1;
  q->v2 = temp.v2;
  q->e = temp.e;
}

void partition(struct edge a[],int l,int r,int *p,int *q){
   int i,j;
   double x;
   j = l;
   x = a[l].e;
   for (i=l+1;i<=r;i++){
   	  if (a[i].e<=x){
        j++;
        swap(&a[i],&a[j]);
   	  }
   }
   swap(&a[l],&a[j]);
   *q = j;
   for (i=l;i<j;i++){
   	  if (a[j-1].e == x){
   	  	j--;
   	  }
      if (a[i].e == x && j!=l && j!=i){
      	 swap(&a[i],&a[j-1]);
      	 j--;
      }
   }
   *p = j;
}

void quicksort(struct edge a[],int l,int r){
  int i;
  if (l>=r)
		return;
  int k,m1,m2;
  k = (rand()%(r-l+1)) + l;
  swap(&a[k],&a[l]);
  partition(a,l,r,&m1,&m2);
  quicksort(a,l,m1-1);
  quicksort(a,m2+1,r);
}

double distance(struct point pt1,struct point pt2){
	double v = (sqrt((pt1.x-pt2.x)*(pt1.x-pt2.x) + (pt1.y-pt2.y)*(pt1.y-pt2.y)));
	return v;
}

void union1(int a,int b){
	int x = find(a);
	int y = find(b);
	if(x == y)
	  return;
    if(rank1[x]>rank1[y])
    	parent[y] = x;
    else{
    	parent[x] = y;
    	if(rank1[x] == rank1[y])
    		rank1[y] += 1;
    }
}

double kruskal(struct edge edge[],int k,int n){
   quicksort(edge,0,k);
   int x = 0;
   double sum = 0;
   for(int i=1;i<=n;i++)
   	  makeset(i);
   for(int i=0;i<=k;i++){
      if(find(edge[i].v1) != find(edge[i].v2)){
      	  sum += edge[i].e;
      	  union1(edge[i].v1,edge[i].v2);
      }
   } 
   return sum;
}

int main(){
   int n,m,x,y,e,u,v;
   cin >> n;
   struct point points[n+1];
   for(int i = 1;i<n+1;i++){
   	  cin >> points[i].x >> points[i].y;   	  
   }
   struct edge edge[n*n];
   parent.resize(n+1);
   rank1.resize(n+1);
   int k = 0;
   for(int i=1;i<=n;i++){
   	  for(int j=1;j<=n;j++){
   	  	 double x = distance(points[i],points[j]);
   	  	 if(x != 0){
   	  	 	edge[k].v1 = i;
   	  	 	edge[k].v2 = j;
   	  	 	edge[k++].e = x;
   	  	 }
   	  }
   }
   cout.precision(10);
   cout << fixed <<  kruskal(edge,k-1,n);
}