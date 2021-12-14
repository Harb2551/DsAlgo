// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        int ans = 0;
        int count=0,temp=0;
        int n = s.length();
        stack <int> x;
        x.push(-1);
        for(auto i=0;i<n;i++){
            if(s[i]=='(')
                x.push(i);
            else{
                x.pop();
                if(x.empty()){
                    x.push(i);
                }
                else{
                   count = i-x.top();
                   ans = max(ans,count);
                }
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
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends