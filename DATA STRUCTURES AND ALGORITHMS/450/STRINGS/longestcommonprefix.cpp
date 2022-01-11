class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n = strs.size();
        int s = min(strs[0].length(),strs[n-1].length());
        string ans;
        for(auto i=0;i<s;i++){
            if(strs[0][i]!=strs[n-1][i])
                return ans;
            ans += strs[0][i];
        }
        return ans;
    }
};