class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = abs(dividend);
        long long b = abs(divisor);
        long long temp=0,q=0;
        for(auto i=31;i>=0;i--){
            if((temp+(b<<i))<=a){
                temp += b<<i;
                q += 1LL<<i;
            }
        }     
        q = (dividend>=0 ^ divisor>=0) ? -q : q;
        if(q<INT_MIN || q>INT_MAX) return INT_MAX;
        return q;
    }
};