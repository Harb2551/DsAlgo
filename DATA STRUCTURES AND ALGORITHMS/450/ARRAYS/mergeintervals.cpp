class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size(),last=0;
        for(auto i=1;i!=n;i++){
            if(intervals[i][0]>=intervals[last][0] && intervals[i][0]<=intervals[last][1]){
              if(intervals[i][1]>=intervals[last][1]){
                intervals[i][0] = intervals[last][0];
                intervals[last][0] = -1;
                last = i;
              }
              else{
                  intervals[i][0] = -1;
              }
            }
            else
                last = i;
        }
        vector <vector <int>> v;
        for(auto i=intervals.begin();i!=intervals.end();i++){
            if(*(i->begin())!=-1){
                v.push_back(*i);
            }
        }      
        return v;
    }
};