#include <stdio.h>

int merge(int *a,int l,int mid,int r){
	int i=l,j=mid+1,t[r+1],s = 0,inv=0;
	if (l==r)
		return 0;
	while(i<=mid){
		for(j=mid+1;j<=r;j++){
			if (a[i]>a[j])
				inv++;
		}
		i++;
	}
	i=l,j=mid+1;
    while(mid-i >= 0 && r-j >= 0){
      if (a[j]>=a[i]){
         t[s] = a[i];
         i++;
         s++;
      }
      else{
      	t[s] = a[j];
      	j++;
      	s++;
      	}
    }
    if (j>r){
       for(i;i<=mid;i++,s++){
       	  t[s] = a[i];
       }
    }
    else if(i>mid){
    	for(j;j<=r;j++,s++){
    		t[s] = a[j];
    	}
    }
    for(i=l,j=0;i<=r;i++,j++)
    	a[i] = t[j];
    return inv;
} 

int mergesort(int *a,int l,int r){
  int inv = 0;	
  if (l<r){
	int mid = (l+r)/2;
    inv += mergesort(a,l,mid);
	inv += mergesort(a,mid+1,r);
    inv += merge(a,l,mid,r);                                  
    }
    return inv;
}

int main(){
	int size,inv;
	scanf("%d",&size);
	int a[size],i;
	for(i=0;i<size;i++){
		scanf("%d",&a[i]);
	}
    inv = mergesort(a,0,size-1);
    printf("%d",inv);
    // for(i=0;i<size;i++){
    // 	printf("%d ",a[i]);
    // }
}