#include <bits/stdc++.h>
using namespace std;

void swap(long long int *a,long long int *b){
    long long int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    long long int n,k;
	    cin >> n >> k;
	    long long int h[n];
	    for(int i=0;i<n;i++){
	        cin >> h[i];
	    }
	    sort(h,h+n,greater<int>());
	    long long int j=0,sum=0;
	    while(sum<k && j!=n){
	        sum += h[j++];
	    }
	    if(sum<k && j==n)
	      cout << -1 << endl;
	    else{
	        long long int x = j-1;
	         for(int i = x;i>=0;i--){
	          j = x + 1;
	          while(1){
	            if(sum-h[i]+h[j]>=k && j!=n){
	               j++;
	            }
	            else 
	              break;
	          }
	          if(j != x + 1){
	            sum = sum - h[i] + h[j-1];
	            swap(&h[i],&h[j-1]);
	            for(int s = j-1;s>x+1;s--){
	              swap(&h[s],&h[s-1]);
	            }
	          }
	          if(sum==k)
	            break;
	        }
	        long long int l = 0,y = x+1,sum1 = 0;
	        while(sum1<k && y!=n){
	            sum1 += h[y++];
	            l++;
	        }
	        if(sum1<k)
	          cout << -1 << endl;
	        else
	          cout << x + 1 + l << endl;
	  }
	}
	return 0;
}

 // for(int i = 0;i<=x;i++){
	       //   j = x + 1;
	       //   while(1){
	       //     if(sum-h[i]+h[j]>=k && j!=n){
	       //        j++;
	       //     }
	       //     else 
	       //       break;
	       //   }
	       //   if(j != x + 1){
	       //     sum = sum - h[i] + h[j-1];
	       //     swap(&h[i],&h[j-1]);
	       //    // for(int s = j-1;s>x+1;s--){
	       //    //   swap(&h[s],&h[s-1]);
	       //    // }
	       //    int a[n],i=0,r = x+1;
	       //    while(r!=n){
	       //        a[i++] = h[r++];
	       //    }
	       //    sort(a,a+i,greater<int>());
	       //    i=x+1,r=0;
	       //    while(i!=n){
	       //        h[i++] = a[r++];
	       //    }
	       //   }
	       //   if(sum==k)
	       //     break;
	       // }
