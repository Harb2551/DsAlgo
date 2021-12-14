#include <stdio.h>

long long int gcd(long long int a,long long int b){
	if (b == 0){
		return a;
		}
    long long int rem = a%b;
    gcd(b,rem);
}

int main(){
	long long int a,b,ans;
	scanf("%lld %lld",&a,&b);
	if (a > b){
	  ans = gcd(a,b);
	   }
	else{
	  ans = gcd(b,a);
	 }
    printf("\n%lld",ans);
}