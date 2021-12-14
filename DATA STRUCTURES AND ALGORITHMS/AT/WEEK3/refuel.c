#include <stdio.h>

int refuel(int stops[],int size,int d,int m){
     int i,j=0,dis = 0,total = 0,refill = 0,last = 0;
     if (stops[0]>m){
     	return -1;
     }
     for (i=0;i<size-1;i++){
     	if (stops[i+1] - stops[i] > m){
     		return -1;
     	}
        if (stops[i+1]-last>m){
              refill++;
              last = stops[i];
          }
             }
     return refill;
}      

int main(){
	int size,d,m,i,ans;
	scanf("%d\n%d\n%d",&d,&m,&size);
	int stops[size+1];
	for (i=0;i<size;i++){
		scanf("%d",&stops[i]);
	}
	stops[size] = d;
	ans = refuel(stops,size+1,d,m);
    printf("%d",ans);
}