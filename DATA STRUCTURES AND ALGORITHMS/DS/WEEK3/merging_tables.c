#include <stdio.h>

int max_size = 0;

int find(int parent[],int i){
	if(parent[i] != i){
		parent[i] = find(parent,parent[i]);
	}
	return parent[i];
}

void merge(int d,int s,int parent[],int size[]){
   int pd = find(parent,d-1);
   int ps = find(parent,s-1);
   if (pd == ps){
   	  return;
   }
   else{
      size[pd] += size[ps];
      size[ps] = 0;
      parent[ps] = pd;
      if (size[pd] > max_size){
      	max_size = size[pd];
      }
   }
}

int main(){
	int n,m,i;
	scanf("%d %d",&n,&m);
	int size[n],parent[n];
	int q[m][2],max[m];
	for(i=0;i<n;i++){
	   scanf("%d",&size[i]);
	   if (size[i] > max_size){
	   	  max_size = size[i];
	   }
	}
	for(i=0;i<m;i++){
		scanf("%d %d",&q[i][0],&q[i][1]);
	}
    for(i=0;i<n;i++){
    	parent[i] = i;
    }
    for(i=0;i<m;i++){
    	merge(q[i][0],q[i][1],parent,size);
    	max[i] = max_size;
    }  
    for(i=0;i<m;i++){
    	printf("%d\n",max[i]);
    }
}



