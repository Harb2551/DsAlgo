#include <stdio.h>

void bubble_sort(long long int *array,int size){
	int i=0,j=0;
    for (i=0;i<size-1;i++){
    	for (j=0;j<size-i-1;j++){
    	  if (array[j+1]<array[j]){
    		long long int temp = array[j];
    		array[j] = array[j+1];
    		array[j+1] = temp;
    	    }
    	}
    }
}

long long int ads(long long int cost[],long long int click[],int size){
	 long long int c = 0;
	 int i;
     for (i=0;i<size;i++){
         c += cost[i]*click[i];
     }
     return c;
}

int main(){
	int size,i;
	long long int ans;
	scanf("%d",&size);
	long long int cost[size],click[size];
	for (i=0;i<size;i++){
		scanf("%lld",&cost[i]);
	}
	for (i=0;i<size;i++){
		scanf("%lld",&click[i]);
	}
	bubble_sort(cost,size);
	bubble_sort(click,size);
	ans = ads(cost,click,size);
	printf("%lld",ans);
}