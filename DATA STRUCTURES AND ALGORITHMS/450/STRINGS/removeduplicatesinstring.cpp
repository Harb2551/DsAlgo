// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
	    map <char,int> mp;
	    string s;
	    int n = str.length();
	    for(auto i=0;i<n;i++){
	        if(!mp[str[i]]){
	            mp[str[i]] = 1;
	            s.push_back(str[i]);
	        }
	    }
	    return s;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends