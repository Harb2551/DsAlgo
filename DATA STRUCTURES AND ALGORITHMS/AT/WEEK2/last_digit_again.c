#include <stdio.h>

unsigned long long int fibonacci(int n){
    unsigned long long int f[n+1];
	int i;
	f[0] = 0;
	f[1] = 1;
	for (i=2;i<=n;i++){
	   
        f[i] = f[i-2] + f[i-1];
      }
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

unsigned long long int sum_last(unsigned long long int n,unsigned long long int m){
   int p = pisano_period(10);
   int r1 = (n + 2) % p;
   int r2 = (m + 1) % p;
   unsigned long long int f1 = fibonacci(r1);
   unsigned long long int f2 = fibonacci(r2);
   return (f1-f2) % 10;
}

int main(){
  unsigned long long int n,m,ans;
  scanf("%llu %llu",&m,&n);
  ans = sum_last(n,m);
  printf("%llu",ans);
}