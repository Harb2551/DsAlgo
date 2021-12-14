// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        priority_queue <pair<char,int>,vector <pair<int,char>>> pq;
        int n = s.length();
        map <char,int> mp;
        for(auto i=0;i<n;i++)
            mp[s[i]]++;
        for(auto i=mp.begin();i!=mp.end();i++)
            pq.push({i->second,i->first});
        for(auto i=0;i<k;i++){
            pair <int,char> p = {pq.top().first-1,pq.top().second};
            pq.pop();
            pq.push(p);
        }
        int ans=0;
        while(!pq.empty()){
            ans += (pq.top().first)*(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends