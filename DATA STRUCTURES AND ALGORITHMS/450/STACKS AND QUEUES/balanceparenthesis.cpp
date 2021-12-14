// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    char opp(char x){
        if(x=='[')
            return ']';
        if(x=='(')
            return ')';
        if(x=='{')
            return '}';
    }
    
    bool ispar(string x)
    {
        // Your code here
        stack <int> s;
        for(auto i=0;i<x.length();i++){
            if(x[i]=='{' or x[i]=='[' or x[i]=='(')
                s.push(x[i]);
            else{
                if(s.empty() or opp(s.top())!=x[i])
                    return false;
                else{
                    s.pop();
                }
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