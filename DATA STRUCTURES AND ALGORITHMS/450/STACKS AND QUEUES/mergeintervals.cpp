/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/
#include <bits/stdc++.h>
using namespace std;

bool compare(const vector <int> &v1,const vector <int> &v2){
    if(v1[0]==v2[0])
        return v1[1]<v2[1];
    return v1[0]<v2[0];
}

vector<vector<int>> mergeIntervals(vector<vector<int>> intervals)
{
    // Write your code here
    sort(intervals.begin(),intervals.end(),compare);
    stack <vector<int>> s;
    int n = intervals.size();
    for(auto i=0;i<n;i++){
        if(s.empty() or (intervals[i][1]>s.top()[1] and intervals[i][0]>s.top()[1]))
            s.push(intervals[i]);
        else if(intervals[i][1]>s.top()[1] and intervals[i][0]<=s.top()[1])
            s.top()[1] = intervals[i][1];
    }
    intervals.clear();
    intervals.resize(s.size());
    int j=s.size()-1;
    while(!s.empty()){
        intervals[j--] = s.top();
        s.pop();
    }
    return intervals;
}








