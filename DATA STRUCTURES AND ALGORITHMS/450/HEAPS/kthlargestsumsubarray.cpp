#include <bits/stdc++.h>
using namespace std;

int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
    vector <long> v;
    int n = arr.size();
    priority_queue <long,vector<long>,greater<long>> pq;
    for(auto i=0;i<n;i++){
        long sum = 0;
        for(auto j=i;j<n;j++){
            sum += arr[j];
            if(pq.size()<k)
            	pq.push(sum);
            else{
                if(sum>pq.top()){
                    pq.pop();
                    pq.push(sum);
                }
            }            
        }
    }
    return pq.top();
}