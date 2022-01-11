#include <bits/stdc++.h>
using namespace std;

unordered_map<char,int> badmatch(string &pat){
    int n = pat.length();
    unordered_map <char,int> mp1;
    for(auto i=0;i<256;i++)
        mp1[i] = -1;
    for(auto i=0;i<n;i++){
         mp1[pat[i]] = i;
    }
    return mp1;
}

vector<int> patternSearch(string &text, string &pattern) {
    // Write your code here.
    unordered_map <char,int> mp1;
    int n = pattern.length();
    mp1 = badmatch(pattern);
    vector <int> v;
    int len = text.length();
    int i = 0;
    while(i<=len-n){
        int j = n-1;
        while(j>=0 and text[i+j]==pattern[j]) j--;
        if(j<0){
            v.push_back(i);
            i += ((i+n)<len) ? n-mp1[text[i+n]] : 1;
        }
        else{
            i += max(1,j-mp1[text[i+j]]);
        }
    }
    if(v.empty())
        return {-1};
    return v;
}