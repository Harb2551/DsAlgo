#include <stdio.h>

void bubble_sort(double *array,int size){
	int i,j;
    for (i=1;i<size;i++){
    	for (j=0;j<=size-i-1;j++){
    		if (array[j]<array[j+1]){
    		    double temp = array[j];
    		    array[j] = array[j+1];
    		    array[j+1] = temp;	
    		}
    	}
    }
}

int min(int a,int b){
	if (a<b)
	  return a;
	else
	  return b;
}

double knapsack(double w[],double v[],double W,int size){
	int i;
	double m,ans;
	for (i=0;i<size;i++){
		if (W == 0){
			return ans;
		}
		m = min(W,w[i]);
		ans += (v[i]/w[i])*m;
		W -= m;
	}
}

int main(){
	int size,i;
	double W,ans;
	scanf("%d %lf",&size,&W);
    double w[size],v[size];
    for (i=0;i<size;i++){
    	scanf("%lf %lf*1[\n]", &v[i],&w[i]);
    }
    bubble_sort(w,size);
    bubble_sort(v,size);
    for (i=0;i<size;i++){
    	printf("%lf %lf\n",v[i],w[i]);
    }
    ans = knapsack(w,v,W,size);
    printf("\n%lf",ans);
}