class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() < 2){
            return nums[0];
        }
        
        int sum = 0;
        int maxSum = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum > maxSum){
                maxSum = sum;
            }
            if(sum < 0){
                sum = 0;
            }
            
        }
        return maxSum;
        
        
    }
};