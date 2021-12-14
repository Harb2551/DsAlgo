#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0,buy=prices[0],profit=0,n=prices.size();
        for(auto i=1;i<n;i++){
           if(prices[i]<buy && i!=n-1){
               buy = prices[i];
           }
           if(prices[i]-buy>profit)
               profit = prices[i]-buy;
        }
        return profit;
    }
};

int main()
{
  ll t;
  cin>>t;
  return 0;
}
