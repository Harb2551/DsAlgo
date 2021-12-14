N #include <stdio.h>
#include <string.h>

int min(int a,int b,int c){
   if(a<=b && a<=c)
   	return a;
   if(b<=a && b<=c)
   	return b;
   if(c<=a && c<=b)
   	return c;
}

int edit_distance(char a[],char b[]){
   int ans[strlen(a)+2][strlen(b)+2],i,j,insertion,deletion,mismatch,match;
   for(i=0,j=0;j<strlen(b)+1;j++){
   	   ans[i][j] = j;
   } 
   for(i=0,j=0;i<strlen(a)+1;i++){
   	  ans[i][j] = i;
   }
   for(j=1;j<strlen(b)+1;j++){
   	  for(i=1;i<strlen(a)+1;i++){
         insertion = ans[i][j-1] + 1;
         deletion = ans[i-1][j] + 1;
         mismatch = ans[i-1][j-1] + 1;
         match = ans[i-1][j-1];
         if (a[i-1] == b[j-1])
         	ans[i][j] = min(insertion,deletion,match);
         else
            ans[i][j] = min(insertion,deletion,mismatch);   	  
   	  }
   }
 
 return ans[strlen(a)][strlen(b)];
}

int main(){
	char a[100],b[100];
    scanf("%s",&a);
    scanf("%s",&b);
    printf("%d",edit_distance(a,b));

}