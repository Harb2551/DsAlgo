#include <stdio.h>
#include <string.h>



int max2(int a,int b){
	return a>=b ? a : b;
}

int lonsub2(int a[],int b[],int a1,int b1){
	int i,j,ans[a1+1][b1+1],count = 0;
    for(j=0;j<b1+1;j++){
    	for(i=0;i<a1+1;i++){
    		if (i==0 || j==0)
    			ans[i][j] = 0;
    		else if (a[i-1] == b[j-1]){
                ans[i][j] = ans[i-1][j-1] + 1;
    		}
    		else{
    			ans[i][j] = max2(ans[i-1][j],ans[i][j-1]);
    		}
    	}
    }
    return ans[a1][b1];
} 

int main(){
	int i,a1,b1;
	scanf("%d",&a1);
	int a[a1];
	for (i=0;i<a1;i++)
		scanf("%d",&a[i]);
	scanf("%d",&b1);
	int b[b1];
	for(i=0;i<b1;i++)
		scanf("%d",&b[i]);
	printf("%d",lonsub2(a,b,a1,b1));
}