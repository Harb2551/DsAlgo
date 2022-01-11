// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    // your code here
    int n = s.length();
    if(n&1)
        return -1;
    stack <char> s1;
    int c1=0,c2=0;
    for(auto i=0;i<n;i++){
        if(s[i]=='{'){
            s1.push(s[i]);
            c1++;
        }
        else if(s[i]=='}' and !s1.empty() and s1.top()=='{'){
            s1.pop();
            c1--;
        }
        else
            c2++;
    }
    if(c2&1)
        return ceil(c2/2.0) + ceil(c1/2.0);
    return c2/2 + c1/2;
}