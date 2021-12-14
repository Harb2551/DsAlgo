#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(char a[],char b[]){
	char c[100];
	char d[100];
	strcpy(c,a);
	strcpy(d,b);
	strcat(c,b);
	strcat(d,a);
	if (atoi(c)>atoi(d))
	   return atoi(a);
	else
	   return atoi(b);
}

void delete(int *array,int index,int size){
	int i;
	for (i=index;i<size;i++){
		array[i] = array[i+1];
	}
}

void max_salary(int num[],int size){
	int max;
	int i,index;
	char ans[100000],max1[100],n[100];
	int len = size;
	while (len > 0){
		strcpy(max1,"0");
        for (i=0;i<len;i++){
			sprintf(n,"%d",num[i]);
            sprintf(max1,"%d",compare(max1,n));
			 if (strcmp(max1,n) == 0){
             	index = i;
             	}
		}
	    delete(num,index,len);
		len -= 1;
		strcat(ans,max1);
     }
	printf("%s",ans);
}

int main(){
	int size,i;
	scanf("%d",&size);
	int num[100];
    for (i=0;i<size;i++){
	  scanf("%d",&num[i]);
    }
    max_salary(num,size);
}