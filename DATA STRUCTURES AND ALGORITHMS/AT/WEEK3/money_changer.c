#include <stdio.h>

int money_changer(int money){
	int i,change = 0,den[] = {10,5,1};
	for (i=0;i<3;i++){
		change += money/den[i];
		money -= (money/den[i])*den[i];
    }
    return change;
}

int main(){
   int m,ans;
   scanf("%d",&m);
   ans = money_changer(m);
   printf("%d",ans);
}