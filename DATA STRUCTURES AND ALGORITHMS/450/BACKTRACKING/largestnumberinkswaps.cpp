// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    
    string compare(string temp,string ans){
        int n = temp.length();
        int m = ans.length();
        int i=0,j=0;
        while(i<n and j<m){
            if(temp[i]>ans[j]){
                return temp;
            }
            if(temp[i]<ans[j]){
                return ans;
            }
            i++;
            j++;
        }
        return i<n ? temp : ans;
    }
    
    void solve(string &str,int k,int &count,int i,int n,string &ans){
        if(count==k or i==n){
            return;
        }
        int k1;
        char mm = str[i];
        for(k1=i+1;k1<n;k1++){
            mm = max(mm,str[k1]);
        }
        if(str[i]!=mm)
            count++;
        for(auto j=i;j<n;j++){
            if(str[j]==mm){
                swap(str[i],str[j]);
                ans = compare(ans,str);
                solve(str,k,count,i+1,n,ans);
                swap(str[i],str[j]);
            }
        }
        if(str[i]!=mm)
            count--;
    }
    
    string findMaximumNum(string str, int k)
    {
       // code here.
       string ans=str,temp=str;
       int n = str.length();
       int count = 0;
       solve(str,k,count,0,n,ans);
       return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends