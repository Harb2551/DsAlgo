#include <stdio.h>

void fibonacci(int n){
	int f[n+1],i;
	f[0] = 0;
	f[1] = 1;
	for (i=2;i<=n;i++){
       f[i] = (f[i-2] + f[i-1])%10;
	}
	printf("\n%lld",f[n]);
}

int main(){
	int n;
	scanf("%d",&n);
	fibonacci(n);
}