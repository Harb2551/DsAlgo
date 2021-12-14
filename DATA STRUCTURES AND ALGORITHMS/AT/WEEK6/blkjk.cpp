#include <bits/stdc++.h>
using namespace std;

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int one(int a[],int i,int x,int y,int n,int sum){
    for(int k=0;k<i;k++){
        swap(&a[k],&a[i]);
        int sum1=0,p;
        for(p=0;p<n;p++){
            sum1 += a[p];
            if(sum1>=x && sum1<=y)
              return 1;
            if(sum1>=x)
              break;
        }
        swap(&a[k],&a[i]);
        // if(sum - a[k] >= x && sum-a[k]<=y)
        //   return 1;
    }
    for(int k=i+1;k<n;k++){
        for(int j=0;j<i+1;j++){
            swap(&a[k],&a[j]);
            int sum1=0;
            for(int p=0;p<n;p++){
                sum1 += a[p];
                if(sum1>=x && sum1<=y)
                  return 1;
                if(sum1>=x)
                  break;
            }
            swap(&a[k],&a[j]);
            // if(sum-a[j]+a[k]>=x && sum-a[j]+a[k]<=y){
            //     return 1;
            // }
        }
    }
    return 0;
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n,x,y,w=1,v=0;
	    cin >> n >> x >> y;
	    int a[n],sum=0;
	    for(int i=0;i<n;i++){
	        cin >> a[i];
	    }
	    int i;
	    for(i=0;i<n;i++){
	        sum += a[i];
	        if(sum>=x)
	          break;
	    }
	   // cout << "i=" << i << endl;
	    if(sum<x){
	      cout << -1 << endl;
	      v=1;
	    }
	    else if(sum>=x && sum<=y){
	      cout << 0 << endl;
	      v=1;
	    }
	    else{
	       // sum -= a[i];
	        if(one(a,i,x,y,n,sum)){
	          cout << 1 << endl;
	          v=1;
	        }
	        else{
	          for(int p=i+1;p<n;p++){
	              for(int q=0;q<i+1;q++){
	                  swap(&a[q],&a[p]);
	                  int l,sum1=0;
	                  for(l=0;l<n;l++){
	                      sum1 += a[l];
	                      if(sum1>=x)
	                        break;
	                  }
	                  if(one(a,l,x,y,n,sum1)){
	                      cout << 2 << endl;
	                      w = 0;
	                      v=1;
	                      break;
	                  }
	                  swap(&a[q],&a[p]);
	              }
	              if(!w)
	                break;
	              for(int k=0;k<i;k++){
	                  swap(&a[k],&a[i]);
	                  int j,sum1=0;
	                  for(j=0;j<n;j++){
	                      sum1 += a[j];
	                      if(sum1>=x)
	                        break;
	                  }
	                  if(one(a,j,x,y,n,sum1)){
	                      cout << 2 << endl;
	                      v=1;
	                      break;
	                  }
	                  swap(&a[k],&a[i]);
	              }
	          }
	        }
	        if(!v)
	          cout << -1 << endl;
	    }
	    
	}
	return 0;
}
