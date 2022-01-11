#include <bits/stdc++.h>
using namespace std;

int lps(string s){
    int n = s.length();
    vector <int> v(n,0);
    for(auto i=1;i<n;i++){
        int j = v[i-1];
        while(j>0 and s[i]!=s[j])
            j = v[j-1];
        if(s[i]==s[j])
            v[i] = j+1;
    }
    return v[n-1];
}

int minCharsforPalindrome(string str) {
	// Write your code here.
 	string s1 = str;
    reverse(s1.begin(),s1.end());
    string s = str + '$' + s1;
    int ans = lps(s);
   	int n = str.length();
    return n - ans;
}
