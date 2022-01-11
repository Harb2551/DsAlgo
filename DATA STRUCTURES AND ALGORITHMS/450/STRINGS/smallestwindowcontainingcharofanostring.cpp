// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow(string &s, string &p)
    {
        // Your code here
        int mp1[256],mp2[256];
        memset(mp1,0,sizeof(mp1));
        memset(mp2,0,sizeof(mp2));
        int n = s.length();
        int m = p.length();
        if(m>n)
            return "-1";
        int count = 0;
        for(auto i=0;i<m;i++){
            if(!mp1[p[i]])
                count++;
            mp1[p[i]]++;
        }
        int i=0,j=0;
        int c=0,win=INT_MAX;
        int index1 = -1,index2 = -1;
        while(i<n){
            mp2[s[i]]++;
            if(mp1[s[i]] and mp2[s[i]]==mp1[s[i]]){
                c++;
            }
            while(j<=i and mp2[s[j]]>mp1[s[j]]){
                mp2[s[j]]--;
                j++;
            }
            if(c==count){
                if(win>i-j+1){
                    win = i-j+1;
                    index1 = j;
                    index2 = i;
                }
            }
            i++;
        }
        if(index1==-1)
            return "-1";
        return s.substr(index1,index2-index1+1);
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends