class Solution {
public:
    void Subset(vector<vector<int>> &ans, vector<int> nums,vector<int> v){
        if(nums.size()==0){
            ans.push_back(v);
            return;
        }
        int s = nums[0];
        nums.erase(nums.begin());
        Subset(ans,nums,v);
        v.push_back(s);
        Subset(ans,nums,v);
            
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        Subset(ans,nums,v);
        return ans;
    }
};