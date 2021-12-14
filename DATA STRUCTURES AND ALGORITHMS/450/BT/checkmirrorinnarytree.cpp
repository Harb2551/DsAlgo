// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        // code here
        queue <int> q1,q2;
        q1.push(A[0]);
        q2.push(B[0]);
        int p=0;
        int l=0;
        map <int,stack<int>> mp1;
        map <int,queue<int>> mp2;
        while(!q1.empty()){
            if(p>=2*e)
                break;
            int m1 = q1.size();
            int m2 = q2.size();
            for(auto i=0;i<m1;i++){
                q1.pop();
                auto cur = A[p];
                while(p<2*e and cur==A[p]){
                    q1.push(A[p+1]);
                    mp1[cur].push(A[p+1]);
                    p+=2;
                }
                q2.pop();
                auto temp=B[l];
                while(l<2*e and temp==B[l]){
                    q2.push(B[l+1]);
                    mp2[temp].push(B[l+1]);
                    l+=2;
                }
            }
        }
        for(auto i=mp1.begin();i!=mp1.end();i++){
                if(i->second.size()!=mp2[i->first].size())
                    return false;
                while(!i->second.empty()){
                    if(i->second.top()!=mp2[i->first].front())
                        return false;
                    i->second.pop();
                    mp2[i->first].pop();
                }
        }
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends