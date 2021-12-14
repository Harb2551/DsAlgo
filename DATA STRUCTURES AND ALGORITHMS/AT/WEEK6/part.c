#include <stdio.h>

int is_part(int num[],int n,int a,int b,int c){
	int A,B,C;
	if (a == 0 && b==0 && c==0)
		return 1;
	if (n<0)
		return 0;
	A = 0;
	if (a-num[n] >= 0)
		A = is_part(num,n-1,a-num[n],b,c);
	B = 0;
	if (!A && (b-num[n] >= 0))
		B = is_part(num,n-1,a,b-num[n],c);
	C = 0;
	if ((!A && !B) && (c - num[n] >= 0))
		C = is_part(num,n-1,a,b,c-num[n]);
	return (A||B||C);
}

int main(){
	int n,i,sum = 0;
	scanf("%d",&n);
	int num[n];
	for(i=0;i<n;i++)
		scanf("%d",&num[i]);
	for(i=0;i<n;i++)
		sum += num[i];
	if (sum%3 == 0){
		printf("%d",is_part(num,n-1,sum/3,sum/3,sum/3));
	}
	else
		printf("0");

}