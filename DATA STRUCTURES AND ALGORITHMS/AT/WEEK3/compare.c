#include <stdio.h>

int compare(char a,char b){
	char c[4];
	char d[4];
	// printf("%s %s ",a,b);
	strcpy(c,a);
	strcpy(d,b);
	strcat(a,b);
	strcat(b,c);
	// printf("%s %s\n",a,b);
	if (atoi(a)>atoi(b))
	   return atoi(c);
	else
	   return atoi(d);
}

int main(){
    int size,ans;
	char a[size],b[size];
	ans = compare(a,b);
    printf("%d",ans)
}