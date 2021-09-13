class Solution {
public:
    int maximumWealth(vector<vector<int>>& nums) {
        int max = 0;
        for(int i = 0; i <nums.size(); i++){
            int sum = 0;
            for(int j = 0; j < nums[i].size(); j++){
                sum += nums[i][j];
                if(sum > max){
                    max = sum;
                }
            }
        }
        return max;
    }
};