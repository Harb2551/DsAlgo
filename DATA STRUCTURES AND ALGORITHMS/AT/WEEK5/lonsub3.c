#include <stdio.h>
#include <string.h>

int max(int a,int b,int c){
  if (a>=b && a>=c)
    return a;
  if (b>=a && b>=c)
    return b;
  if (c>=a && c>=b)
    return c;
}

int lonsub3(int a[],int b[],int c[],int a1,int b1,int c1){
  int i,j,k,ans[a1+1][b1+1][c1+1],len = 0;
  for(k=0;k<=c1;k++){
    for(j=0;j<=b1;j++){
      for(i=0;i<=a1;i++){
        if (i==0 || j==0 || k==0){
          ans[i][j][k] = 0;
        }
        else if(a[i-1] == b[j-1] && b[j-1] == c[k-1]){
           ans[i][j][k] = ans[i-1][j-1][k-1] + 1;
        }
        else {
          ans[i][j][k] = max(ans[i-1][j][k],ans[i][j][k-1],ans[i][j-1][k]);
        }
      }
    }
  }  
  return ans[a1][b1][c1];
}



int main(){
   int i,a1,b1,c1,m1,ans;
   scanf("%d",&a1);
   int a[a1];
   for(i=0;i<a1;i++)
   	scanf("%d",&a[i]);
   scanf("%d",&b1);
   int b[b1];
   for(i=0;i<b1;i++)
   	scanf("%d",&b[i]);
   scanf("%d",&c1);
   int c[c1];
   for(i=0;i<c1;i++)
   	scanf("%d",&c[i]);
   ans = lonsub3(a,b,c,a1,b1,c1);
   printf("%d",ans);
}












