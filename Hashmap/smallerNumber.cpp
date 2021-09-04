class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // vector<int> ans;
        // for(int i = 0; i < nums.size(); i++){
        //     int count = 0;
        //     for(int j = 0; j < nums.size(); j++){
        //         if(nums[i] > nums[j] && i != j){
        //             count++;
        //         }
        //     }
        //     ans.push_back(count);
        // }
        // return ans;
        
        unordered_map<int, int> map;
        vector<int> ans(nums);
        sort(ans.begin(), ans.end());

        for(int i = 0; i < ans.size(); i++){
            map.insert({ans[i], i});
        }
        
        for(int i = 0; i < nums.size(); i++){
            ans[i] = map[nums[i]];
        }
        return ans;
        
    }
};