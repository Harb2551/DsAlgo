class Solution {
public:
    int mySqrt(int x) {
        int l=0,r=x,res=0;
        while(l<=r){
          long long int mid = (l+r)/2;
          if(mid*mid==x)
              return mid;
          if(mid*mid>x)
              r=mid-1;
          else{
              l = mid+1;
              res = mid;
          }
        }
        return res;
    }
};