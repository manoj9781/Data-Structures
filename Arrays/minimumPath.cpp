class Solution {
public:
    int minPathSum(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();
        for(int i = 1; i < m; i++){
            nums[i][0] = nums[i-1][0] + nums[i][0];
        }
        for(int j= 1;j < n; j++){
            nums[0][j] = nums[0][j-1] + nums[0][j];
        }
        for(int i = 1; i < m; i++){
            for(int j = 1;j < n;j++){
                nums[i][j] = min(nums[i][j] + nums[i-1][j], nums[i][j] + nums[i][j-1]);
            }
        }
        return nums[m-1][n-1];
    }
};