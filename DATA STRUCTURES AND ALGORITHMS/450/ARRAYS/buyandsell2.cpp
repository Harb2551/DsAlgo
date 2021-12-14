#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min1=prices[0],max1=prices[n-1];        
        int dp1[n],dp2[n],sum[n];
        dp1[0] = 0;
        dp2[n-1] = 0;
        for(auto i=1;i<n;i++){
            if(prices[i]<min1)
                min1 = prices[i];
            if(prices[i]-min1>dp1[i-1])
                dp1[i] = prices[i]-min1;
            else
                dp1[i] = dp1[i-1];
        }
        for(auto i=n-2;i>=0;i--){
            if(prices[i]>max1)
                max1 = prices[i];
            if(max1-prices[i]>dp2[i+1])
                dp2[i] = max1-prices[i];
            else
                dp2[i] = dp2[i+1];
        }
        int ans = INT_MIN;
        for(auto i=0;i<n;i++){
            sum[i] = dp1[i]+dp2[i];
            if(sum[i]>ans)
                ans = sum[i];
        }
        return ans;
    }
};


int main()
{
  ll t;
  cin>>t;
  return 0;
}
