// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	
	    void solve(string &s,vector <string> &ans,int n,int i,map<string,int> &mp){
	        if(i==n-1)
	            return;
	        for(auto j=i;j<n;j++){
	            swap(s[i],s[j]);
	            if(!mp[s]){
	                ans.push_back(s);
	                mp[s] = 1;
	            }
	            solve(s,ans,n,i+1,mp);
	            swap(s[i],s[j]);
	        }
	    }
	
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    map <string,int> mp;
		    vector <string> ans;
		    solve(S,ans,S.length(),0,mp);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends