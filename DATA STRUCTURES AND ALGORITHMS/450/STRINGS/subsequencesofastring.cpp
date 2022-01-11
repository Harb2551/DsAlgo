vector<string> subsequences(string str){
	
	// Write your code here
	int n = str.length();
    vector <string> ans;
    for(auto i=1;i<1<<n;i++){
        string s;
        for(auto j=n-1;j>=0;j--){
            if((i&(1<<j))!=0)
                s.push_back(str[n-j-1]);
        }
        ans.push_back(s);
    }
    return ans;
}
