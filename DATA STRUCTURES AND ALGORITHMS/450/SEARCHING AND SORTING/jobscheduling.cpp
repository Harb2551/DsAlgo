class job{
 public:
    int start;
    int end;
    int profit;
};

bool compare(const job arr1,const job arr2) {
        return arr1.end<arr2.end;
}

class Solution {
public:    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        job c[n];
        for(auto i=0;i<n;i++){
            c[i].start = startTime[i];
            c[i].end = endTime[i];
            c[i].profit = profit[i];
        }
        sort(c,c+n,compare);
        int dp[n];
        dp[0] = c[0].profit;
        for(auto i=1;i<n;i++){
            int l=0,r=i-1,last=-1;
            while(l<=r){
                int mid = (l+r)/2;
                if(c[mid].end<=c[i].start){
                    last = mid;
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
            int inc = last!=-1 ? c[i].profit + dp[last] : c[i].profit;
            dp[i] = max(inc,dp[i-1]);
        }
        return dp[n-1];
    }
};






