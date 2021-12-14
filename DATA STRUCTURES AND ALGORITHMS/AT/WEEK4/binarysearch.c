#include <stdio.h>

int BinarySearch(int a[],int key,int l,int r){
	if (l > r){
       return -1;
    }
	int mid = (l+r)/2;
    if (a[mid] == key){
    	return mid;
    }
    else if (key < a[mid]){
        return BinarySearch(a,key,l,mid-1);
    }
    else if (key > a[mid]){
        return BinarySearch(a,key,mid+1,r);
    }
}

int main(){
	int n,k,i;
	scanf("%d",&n);
	int a[n];
	for (i=0;i<n;i++){
	   scanf("%d",&a[i]);
	}
	scanf("\n%d",&k);
	int key[k];
	for (i=0;i<k;i++){
		scanf("%d",&key[i]);
	}
	for (i=0;i<k;i++){
		printf("%d ",BinarySearch(a,key[i],0,n-1));
	}
}