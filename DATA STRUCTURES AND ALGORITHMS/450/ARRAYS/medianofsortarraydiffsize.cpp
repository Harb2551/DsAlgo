class Solution {
public:
    double median(vector <int> nums, int i, int j) {
        int n = nums.size();
        double m1;
        if (n & 1) {
            m1 = nums[(i + j) / 2];
        }
        else {
            m1 = (nums[(i + j) / 2] + nums[(i + j) / 2 + 1]) / 2.0;
        }
        return m1;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0)
            return median(nums2, 0, nums2.size() - 1);
        if (nums2.size() == 0)
            return median(nums1, 0, nums1.size() - 1);
        if (nums1.size() > nums2.size())
            return find_median(nums2, nums1);
        return find_median(nums1, nums2);
    }
    double find_median(vector <int> nums1, vector <int> nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int l = 0, r = n;
        while (l <= r) {
            int cut1 = ceil((l + r) / 2.0);
            int cut2 = ceil((n + m) / 2.0) - cut1;
            int l1, l2, r1, r2;
            l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            r1 = cut1 == n ? INT_MAX : nums1[cut1];
            r2 = cut2 == m ? INT_MAX : nums2[cut2];
            if (l1 <= r2 && l2 <= r1) {
                if ((n + m) & 1)
                    return max(l1, l2);
                else
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if (l1 > r2)
                r = cut1 - 1;
            else
                l = cut1 + 1;
        }
        return 0;
    }
};