class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
         unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }
       
        for(int i = 0; i < nums.size(); i++){
            int key = nums[i];
            if(map[key] >= 2){
               return key;
           }
        }
        return 0;
        
    }
};