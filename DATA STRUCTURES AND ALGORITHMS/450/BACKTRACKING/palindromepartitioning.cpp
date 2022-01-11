#include <bits/stdc++.h>
using namespace std;

bool ispal(string s){
    int n = s.length();
    int i=0,j=n-1;
    while(i<=j){
        if(s[i]!=s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

void solve(string s,int i,int n,vector <vector<string>> &ans,vector <string> &temp){
    if(i==n){
        ans.push_back(temp);
        return;
    }
    string s1;
    for(auto j=i;j<n;j++){
        s1.push_back(s[j]);
        if(ispal(s1)){
            temp.push_back(s1);  
            solve(s,j+1,n,ans,temp);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector <vector<string>> ans;
    vector <string> temp;
    solve(s,0,s.length(),ans,temp);
    return ans;
}