#include <stdio.h>

long int gcd(long int a,long int b){
	if (b == 0){
		return a;
		}
    long int rem = a%b;
    gcd(b,rem);
   }

unsigned long long int lcm(long int a,long int b){
   int hcf = gcd(a,b);
   return (a*b)/hcf;
}

int main(){
	long int a,b;
	unsigned long long int ans;
	scanf("%ld %ld",&a,&b);
	ans = lcm(a,b);
	printf("%llu",ans);
}