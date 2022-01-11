#include <bits/stdc++.h>
using namespace std;

int countCustomers(vector<int> &arr, int k)
{
    //    Write your code here
    int n = arr.size();
    int mp[n/2 + 1];
    memset(mp,0,sizeof(mp));
    int count = 0,ans=0;
    for(auto i=0;i<n;i++){
        if(mp[arr[i]]==-1)
            mp[arr[i]] = 0;
        else if(mp[arr[i]]==1){
            mp[arr[i]] = 0;
            count--;
        }
        else if(count<k){
            mp[arr[i]] = 1;
            count++;
        }
        else{
            ans++;
            mp[arr[i]] = -1;
        }
    }
    return ans;
}
