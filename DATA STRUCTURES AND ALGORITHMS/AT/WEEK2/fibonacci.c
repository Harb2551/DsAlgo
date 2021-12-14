#include <stdio.h>

void fibonacci(int n){
    unsigned long long int f[n+1];
	int i;
	f[0] = 0;
	f[1] = 1;
	for (i=0;i<=n;i++){
	   if (i >= 2)
        f[i] = f[i-2] + f[i-1];
      }
	printf("%llu",f[n]);
}

int main(){
	int n;
	scanf("%d",&n);
	fibonacci(n);
}