class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;
        int maxReach = 0;
        int currentReach = 0;
        for(int i = 0; i < nums.size() -1; i++){
            maxReach = max(maxReach, i + nums[i]);
            if(i == currentReach){
                count++;
                currentReach = maxReach;
            }
        }
        return count;
    }
};