#include <stdio.h>
#include <math.h>

int prize(long int n){
	long int d,k,sum,i;
	d = 1 + 8*n;
    k = (sqrt(d) - 1)/2;
    printf("%ld\n",k);
    int ans[k];
    sum = (k*(k-1))/2;
    for (i=1;i<=k-1;i++){
       printf("%ld ",i);
    }
    printf("%ld",n-sum);
}

int main(){
	long int n;
	scanf("%ld",&n);
	prize(n);
}