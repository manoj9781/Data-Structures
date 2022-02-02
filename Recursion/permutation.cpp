class Solution {
public:
    
    void permute(vector<int> nums,  vector<vector<int>> &ans, vector<int> result, int frequency[]){
        if(nums.size() == result.size()){
            ans.push_back(result);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!frequency[i]){
                result.push_back(nums[i]);
                frequency[i] = 1;
                permute(nums, ans, result, frequency);
                result.pop_back();
                frequency[i] = 0;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> result;
        int frequency[6] = {0};
        permute(nums, ans, result, frequency);
        return ans;
        
    }
};