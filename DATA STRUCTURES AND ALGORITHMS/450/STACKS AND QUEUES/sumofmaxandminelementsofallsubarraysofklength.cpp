long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
	// Write your code here.
    long long max_sum=0,min_sum=0;
    deque <int> dq_max,dq_min;
    for(auto i=0;i<n;i++){
        if(!dq_max.empty() and dq_max.front()==i-k)
            dq_max.pop_front();
        if(!dq_min.empty() and dq_min.front()==i-k)
            dq_min.pop_front(); 
        while(!dq_max.empty() and nums[i]>nums[dq_max.back()])
            dq_max.pop_back();
        while(!dq_min.empty() and nums[i]<nums[dq_min.back()])
            dq_min.pop_back();
        dq_max.push_back(i);
        dq_min.push_back(i);
        if(i>=k-1){
            max_sum += nums[dq_max.front()];
            min_sum += nums[dq_min.front()];
        }
    }
    return max_sum + min_sum;
}
