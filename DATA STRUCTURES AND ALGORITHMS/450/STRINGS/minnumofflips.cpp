// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int minFlips (string S)
{
    // your code here
    int n = S.length();
    int a=0,b=0;
    a = S[0]=='0' ? 0 : 1;
    for(auto i=1;i<n;i++){
        if(i&1 and S[i]=='0')
            a++;
        if(!(i&1) and S[i]=='1')
            a++;
    }
    b = S[0]=='1' ? 0 : 1;
    for(auto i=1;i<n;i++){
        if(i&1 and S[i]=='1')
            b++;
        if(!(i&1) and S[i]=='0')
            b++;
    }
    return a>b ? b : a;
}