#include <stdio.h>
#include <string.h>

long long int max(long long int a,long long int b,long long int c){
	if (a>=b && a>= c)
		return a;
	if (b>=a && b>=c)
		return b;
	if (c>=a && c>=b)
		return c;
}

long long int min(long long int a,long long int b,long long int c){
	if (a<=b && a<= c)
		return a;
	if (b<=a && b<=c)
		return b;
	if (c<=a && c<=b)
		return c;
}

long long int max1(long long int a,long long int b,long long int c,long long int d,long long int e){
   long long int s;
   s = max(a,b,c);
   return max(s,d,e);
}

long long int min1(long long int a,long long int b,long long int c,long long int d,long long int e){
   long long int s;
   s = min(a,b,c);
   return min(s,d,e);
}

void max_min(int i,int j,long long int max[][30],long long int min[][30],char op[]){
   long long int a,b,c,d,k,max2 = -1000000,min2 = 1000000;
   for(k=i;k<j;k++){
   	  switch(op[k-1]){
        case '+': a = max[i][k] + max[k+1][j];
   	  	          b = max[i][k] + min[k+1][j];
   	  	          c = min[i][k] + max[k+1][j];
   	  	          d = min[i][k] + min[k+1][j];
   	  	          break;
        case '-': a = max[i][k] - max[k+1][j];
   	  	          b = max[i][k] - min[k+1][j];
   	  	          c = min[i][k] - max[k+1][j];
   	  	          d = min[i][k] - min[k+1][j];
   	  	          break;
   	  	case '*': a = max[i][k] * max[k+1][j];
   	  	          b = max[i][k] * min[k+1][j];
   	  	          c = min[i][k] * max[k+1][j];
   	  	          d = min[i][k] * min[k+1][j];
   	  	          break;
      }
      min2 = min1(min2,a,b,c,d);
      max2 = max1(max2,a,b,c,d);
   }
   max[i][j] = max2;
   min[i][j] = min2;
}

void max_value(int num[],char op[],int size){
	int i,j,s;
	long long int max[30][30],min[30][30];
	for(i=1;i<=size;i++){
		max[i][i] = num[i-1];
		min[i][i] = num[i-1];
	}

	for(s=1;s<size;s++){
		for(i=1;i<=size-s;i++){
			j = i + s;
			max_min(i,j,max,min,op);
        }
    }
	printf("%lld",max[1][size]);
}

int main(){
	char exp[30],op[30];
	int i,j=0,k=0,num[30];
	scanf("%s",exp);
    for(i=0;i<strlen(exp);i++){
       if (i%2 == 0)
         num[j++] = exp[i]-48;
       else
       	 op[k++] = exp[i];
     }
     op[k] = '\0';
    max_value(num,op,j);
}