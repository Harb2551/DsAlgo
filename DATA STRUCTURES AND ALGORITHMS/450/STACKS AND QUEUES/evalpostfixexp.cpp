// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    
    int calc(int a,char op,int b){
        switch(op){
            case '+': return a+b;
            case '-': return a-b;
            case '*': return a*b;
            case '/': return a/b;
        }
    }
    
    int evaluatePostfix(string S)
    {
        // Your code here
        stack <int> num;
        int n = S.length();
        for(auto i=0;i<n;i++){
            if(S[i]>='0' and S[i]<='9')
                num.push(S[i]-48);
            else{
                int a = num.top();
                num.pop();
                int b = num.top();
                num.pop();
                int temp = calc(b,S[i],a);
                num.push(temp);
            }
        }
        return num.top();
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends