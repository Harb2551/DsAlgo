class Solution {
public:
    
    pair<int,int> getmin(string s){
        stack <char> s1;
        int n = s.length();
        for(auto i=0;i<n;i++){
            if(s[i]=='(')
                s1.push('(');
            else if(s[i]==')'){
                if(!s1.empty() and s1.top()=='(')
                    s1.pop();
                else
                    s1.push(')');
            }
        }
        int left=0,right=0;
        while(!s1.empty()){
            if(s1.top()=='(')
                left++;
            else
                right++;
            s1.pop();
        }
        return {left,right};
    }
    
    void solve(string s,int reml,int remr,int left,int right,vector <string> &ans,unordered_map <string,int> &mp,int n){
        if(mp[s])
            return;
        mp[s] = 1;
        if(reml==left and remr==right){
            pair <int,int> p = {0,0};
            if(getmin(s)==p){
                ans.push_back(s);
                mp[s] = 1;
            }
            return;
        }
        for(auto i=0;i<n;i++){
            if(s[i]=='(' and reml<left){
                string a = s.substr(0,i);
                string b = s.substr(i+1);
                solve(a+b,reml+1,remr,left,right,ans,mp,n-1);
            }
            else if(s[i]==')' and remr<right){
                string a = s.substr(0,i);
                string b = s.substr(i+1);
                solve(a+b,reml,remr+1,left,right,ans,mp,n-1);
            }
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        auto a = getmin(s);
        vector <string> ans;
        unordered_map <string,int> mp;
        int n = s.size();
        solve(s,0,0,a.first,a.second,ans,mp,n);
        return ans;
    }
};









