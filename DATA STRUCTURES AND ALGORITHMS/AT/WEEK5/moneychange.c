#include <stdio.h>

int change(int den[],int m,int size){
	int i,ans[m],j,min;
	ans[0] = 0;
	for(i=1;i<=m;i++){
	  	ans[i] = 100000000;
        for(j=0;j<size;j++){
          if(den[j]<=i){	
        	min = ans[i - den[j]] + 1;
            if(min<ans[i])
              ans[i] = min;  
          }
        }
	}
    return ans[m];
}

int main(){
	int m,den[3] = {1,3,4},size = 3;
	scanf("%d",&m);
	printf("%d",change(den,m,size));
}