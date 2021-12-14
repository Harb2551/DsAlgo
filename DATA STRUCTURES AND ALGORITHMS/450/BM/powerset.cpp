// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    int n = s.length();
		    int size = 1<<n;
		    vector <string> v;
		    for(auto i=1;i<size;i++){
		        string a;
		        for(auto j=0;j<32;j++){
		            if(i&(1<<j))
		              a.push_back(s[j]); 
		        }
		        v.push_back(a);
		    }
		    sort(v.begin(),v.end());
		    return v;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends