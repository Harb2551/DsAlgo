#include <stdio.h>

unsigned long long int fibonacci(int n){
    unsigned long long int f[n+1];
	int i;
	f[0] = 0;
	f[1] = 1;
	for (i=0;i<=n;i++){
	   if (i >= 2)
        f[i] = f[i-2] + f[i-1];
      }
    printf("%llu",f[n]);
	return f[n];
}

int pisano_period(int m){
    int previous = 0,current = 1;
    int pp = 0;
    while (1){
    	pp++;
    	int temp = current;
    	current = (previous + current) % m;
    	previous = temp;
    	if (previous == 0 && current == 1){
    		break;
    	}
    }
    return pp;
}

unsigned long long int modulo(unsigned long long int n, int m){
   int p = pisano_period(m);
   int r = n % p;
   unsigned long long int f = fibonacci(r);
   return f % m;
}

int main(){
	int m;
	unsigned long long int n;
	scanf("%llu %d",&n,&m);
	printf("\n%llu",modulo(n,m));
}

