// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        unordered_map <char,int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int n = str.length();
        int i = 0;
        int ans = 0;
        while(i<n){
            if(i==n-1){
                ans += mp[str[i]];
                break;
            }
            if(mp[str[i+1]]>mp[str[i]]){
                ans += mp[str[i+1]]-mp[str[i]];
                i+=2;
            }
            else{
                ans += mp[str[i]];
                i++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}  // } Driver Code Ends