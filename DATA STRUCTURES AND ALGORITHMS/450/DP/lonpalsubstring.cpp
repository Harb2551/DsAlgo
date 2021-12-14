
class Solution {
public:
    
    string longestPalindrome(string s) {
        int n = s.length();
        int dp[n][n];
        pair <int,int> lon;
        if(n==1)
            return s;
        for(auto s1=0;s1<n;s1++){
            for(auto i=0;i<n-s1;i++){
                int j = s1+i;
                if(s1==0)
                    dp[i][j] = 1;
                else if(s1==1)
                    if(s[i]==s[j])
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                else{
                    if(s[i]==s[j] && dp[i+1][j-1])
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                }
                if(dp[i][j])
                    lon = {i,j};
            }
        }
        string a;
        for(auto i=lon.first;i<=lon.second;i++){
            a.push_back(s[i]);
        }
        return a;
    }
};


