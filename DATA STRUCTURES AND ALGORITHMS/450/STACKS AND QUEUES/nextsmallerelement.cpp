#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack <int> s;
    vector <int> ans(n);
    for(auto i=n-1;i>=0;i--){
        while(!s.empty() and arr[i]<=s.top())
            s.pop();
        if(s.empty())
            ans[i] = -1;
        else
            ans[i] = s.top();       
        s.push(arr[i]);
    }
    return ans;
}