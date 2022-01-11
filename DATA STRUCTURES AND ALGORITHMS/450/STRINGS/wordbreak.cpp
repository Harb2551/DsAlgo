// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        //code here
        unordered_map <string,int> mp;
        for(auto i=0;i<B.size();i++){
            mp[B[i]] = 1;
        }
        vector <int> v;
        v.push_back(-1);
        int n = A.length();
        for(auto i=0;i<n;i++){
            for(auto j=0;j<v.size();j++){
                if(mp[A.substr(v[j]+1,i-v[j])]){
                    v.push_back(i);
                    break;
                }
            }
        }
        int size = v.size();
        return v[size-1]==n-1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends