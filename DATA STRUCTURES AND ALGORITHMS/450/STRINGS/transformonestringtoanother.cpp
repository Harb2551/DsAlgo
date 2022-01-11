#include <bits/stdc++.h> 
using namespace std;

int minCostToGivenString(string str1, string str2)
{
    // Write your Code here
    int n = str1.length();
    int m = str2.length();
    if(n!=m)
        return -1;
    map <char,int> mp1,mp2;
    for(auto i=0;i<n;i++)
        mp1[str1[i]]++;
    for(auto i=0;i<m;i++)
        mp2[str2[i]]++;
    if(mp1!=mp2)
        return -1;
    int i=0,j=0,ans=0;
    while(i<n and j<m){
        if(str1[i]==str2[j]){
            i++;
            j++;
        }
        else{
            while(i<n and str1[i]!=str2[j]){
                i++;
                ans++;
            }
        }
    }
    return ans;
}