// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        // code here 
        if(S>D*9)
            return "-1";
        string s="1";
        for(auto i=0;i<D-1;i++){
            s.push_back('0');
        }
        S--;
        int i=D-1;
        while(S!=0){
            if(S>=9){
                s[i--] = '9';
                S -= 9;
            }
            else{
                s[i] = s[i] + S;
                S = 0;
            }
        }
        return s;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
}   // } Driver Code Ends