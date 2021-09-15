class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        for(int i = 1; i < nums.size(); i+= 2){
            while(nums[i-1]--){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};