class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int flag = 0;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                for(auto j=nums.size()-1;j>=i+1;j--){
                    if(nums[j]>nums[i]){
                        int temp = nums[i];
                        nums[i] = nums[j];
                        nums[j] = temp;
                        break;
                    }
                }
                sort(nums.begin()+i+1,nums.end()); // reverse instead
                flag = 1;
                break;
            }
        }
        if(!flag)
            reverse(nums.begin(),nums.end());
    }
};