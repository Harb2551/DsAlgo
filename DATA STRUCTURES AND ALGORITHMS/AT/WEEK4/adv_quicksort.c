#include <stdio.h>
#include <stdlib.h>

void swap(unsigned long long int *p,unsigned long long int *q){
   unsigned long long int temp = *p;
   *p = *q;
   *q = temp;
}

void partition(unsigned long long int *a,long int l,long int r,long int *p,long int *q){
   long int i,j;
   unsigned long long int x;
   j = l;
   x = a[l];
   for (i=l+1;i<=r;i++){
   	  if (a[i]<=x){
        j++;
        swap(&a[i],&a[j]);
   	  }
   }
   swap(&a[l],&a[j]);
   *q = j;
   for (i=l;i<j;i++){
   	  if (a[j-1] == x){
   	  	j--;
   	  }
      if (a[i] == x && j!=l && j!=i){
      	 swap(&a[i],&a[j-1]);
      	 j--;
      }
   }
   *p = j;
}

void quicksort(unsigned long long int *a,long int l,long int r){
  long int i;
  if (l>=r)
		return;
	long int k,m1,m2;
  k = (rand()%(r-l+1)) + l;
  swap(&a[k],&a[l]);
  partition(a,l,r,&m1,&m2);
	quicksort(a,l,m1-1);
	quicksort(a,m2+1,r);
}

int main(){
	long int size,i;
	scanf("%ld",&size);
	unsigned long long int a[size];
	for(i=0;i<size;i++)
		scanf("%llu",&a[i]);
	quicksort(a,0,size-1);
	for(i=0;i<size;i++)
		printf("%llu ",a[i]);
}