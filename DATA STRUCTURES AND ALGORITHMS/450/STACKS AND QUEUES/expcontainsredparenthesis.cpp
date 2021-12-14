#include <bits/stdc++.h>
using namespace std;

bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack <int> s1,s2;
    int n = s.length();
    for(auto i=0;i<n;i++){
        if(s[i]=='(')
            s1.push(i);
        else if(s[i]==')'){
            if(i-s1.top()==2)
                return true;
            if(s2.empty())
                s2.push(i);
            else{            
                int a = s1.top();
                s1.pop();
                int b = s1.top();
                if((a-b==1 and i-s2.top()==1))
                    return true;
                s1.push(a);
                s2.push(i);
            }
        }       
    }
    return false;
}
