#include <stdio.h>

int operations(int n,int minop[]){
	int op[n],i,min;
    op[1] = 0;
    minop[1] = 1;
    for(i=2;i<=n;i++){
       min = 1000000;
       if (i%3==0){
          if(op[i/3]<min){
            min = op[i/3];
            minop[i] = 1; 
          }   
       }
       if(i%2 == 0){
       	  if(op[i/2]<min){
       	  	min = op[i/2];
       	    minop[i] = 2;
       	  }
       }
       if(op[i-1]<min){
          min = op[i-1];
          minop[i] = 3;
       }
       op[i] = min + 1;
    }
    return op[n];
}

int main(){
	int n,count;
	scanf("%d",&n);
	int minop[n+1],ans[n],i;
    count = operations(n,minop);
    ans[1] = 1;
    ans[count+1] = n;
    i = count;
    if (i!=0){
     while(i != 1){
    	switch(minop[n])
    	{
          case 1 : 
            n = n/3;
            ans[i] = n;
            break;
          case 2 :
            n = n/2;
            ans[i] = n;
            break;
          case 3 :
            n = n-1;
            ans[i] = n;
            break;  
    	}
    	i--;
     }
    }
    printf("%d\n",count);
    for(i=1;i<=count+1;i++){
    	printf("%d ",ans[i]);
    }
}
