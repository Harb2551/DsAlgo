// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    
    bool check(stack <char> s,char x){
        if(x==')')
            return s.top()=='(';
        if(x=='}')
            return s.top()=='{';
        if(x==']')
            return s.top()=='[';
        return false;
    }
    
    bool ispar(string x)
    {
        // Your code here
        stack <char> s;
        int n = x.length();
        for(auto i=0;i<n;i++){
            if(x[i]=='(' or x[i]=='{' or x[i]=='[')
                s.push(x[i]);
            else{
                if(s.empty() or !check(s,x[i]))
                    return false;
                s.pop();
            }
        }
        if(s.empty())
            return true;
        return false;
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends