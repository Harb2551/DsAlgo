// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    string findSubString(string str)
    {
        // Your code goes here   
        int n = str.length();
        unordered_map <char,int> mp;
        int win = n;
        for(auto i=0;i<n;i++){
            mp[str[i]] = 1;
        }
        int count = mp.size();
        mp.clear();
        mp[str[0]] = 1;
        int c=1;
        int j=0;
        for(auto i=1;i<n;i++){
            if(!mp[str[i]])
                c++;
            mp[str[i]]++;
            while(mp[str[j]]>1){
                mp[str[j]]--;
                j++;
            }
            if(c==count){
                win = min(win,i-j+1);
            }
        }
        string x;
        for(auto i=0;i<win;i++)
            x += 'a';
        return x;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str).size() << endl;
    }
    return 0;
}  // } Driver Code Ends