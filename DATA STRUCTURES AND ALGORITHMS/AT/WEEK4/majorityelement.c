#include <stdio.h>
int num = 0;

int count(int a[],int l,int r,int x){
	int i,n = 0;
	for (i=l;i<=r;i++){
		if (a[i] == x)
			n++;
	}
	return n;
}

int majority_element(int a[],int l,int r){
	if (l == r)
		return a[l];
	int mid = (l+r)/2;
	int left = majority_element(a,l,mid);
	int right = majority_element(a,mid+1,r);
    if (left == right)
    	return left;
    if (count(a,l,mid,left)>count(a,mid+1,r,right))
        return left;
    return right;
}

int is_majority(int a[],int size){
	int major;
	major = majority_element(a,0,size-1);
	if (count(a,0,size-1,major)>size/2)
		return 1;
	return 0;
}

int main(){
	int size,i;
	scanf("%d",&size);
	int a[size];
	for (i=0;i<size;i++)
	  scanf("%d",&a[i]);
	printf("%d",is_majority(a,size));
}