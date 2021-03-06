class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int count = n*m;
        int low = 0,high = n*m-1;
        while(low<=high){
            int mid = (low+high)/2;
            int i = mid/m;
            int j = mid - i*m;
            if(matrix[i][j]==target)
                return true;
            if(matrix[i][j]>target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
    }
};