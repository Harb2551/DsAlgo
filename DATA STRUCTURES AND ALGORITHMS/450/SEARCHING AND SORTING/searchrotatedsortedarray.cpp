class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index;
        if(nums.size()>1)
            index = find_index(nums);
        else
            return nums[0]==target ? 0 : -1;
        auto ans2 = lower_bound(nums.begin()+index,nums.end(),target);
        // cout << "index" << index << endl;
        
        if(index==0){
          if(ans2==nums.end() || *ans2!=target)
              return -1;
          else
              return ans2-nums.begin();
            // return -1;
        }      
        // auto ans2 = lower_bound(nums.begin()+index,nums.end(),target);
        auto ans1 = lower_bound(nums.begin(),nums.begin()+index-1,target);
        // return *ans1;
        if(ans1!=nums.end() && *ans1==target)
            return ans1-nums.begin();
        else if(ans2!=nums.end() && *ans2==target)
            return ans2-nums.begin();
        else
            return -1;
    }
    
    int find_index(vector <int> nums){
        int n = nums.size();
        int l=0,r=n-1;
        while(l<=r){
           int mid  = (l+r)/2;
           if(nums[mid]>nums[mid+1])
               return mid+1;
           if(nums[l]>nums[mid])
                r = mid;
           else if(nums[r]<nums[mid])
               l = mid+1;
           else
               return 0;
        }
        return  0;
    }
};