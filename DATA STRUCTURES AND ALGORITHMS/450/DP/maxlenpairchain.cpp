class Solution {
public:
    static bool compare(const vector <int> v1,const vector <int> v2){
        return v1[1]<v2[1];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
       sort(pairs.begin(),pairs.end(),compare);
       int n = pairs.size();
       vector <int> dp(n);
       dp[0] = 1;
       for(auto i=1;i<n;i++){
           int l=0,r=i-1,ans=-1;
           while(l<=r){
               int mid = (l+r)/2;
               if(pairs[mid][1]<pairs[i][0]){
                   ans = mid;
                   l=mid+1;
               }
               else
                   r = mid-1;
           }
           dp[i] = ans==-1 ? dp[i-1] : max(dp[i-1],dp[ans]+1);
       }
        return dp[n-1];
    }
};