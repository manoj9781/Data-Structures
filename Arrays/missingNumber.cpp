class Solution {
public:
    int missingNumber(vector<int>& nums) { 
      sort(nums.begin(),nums.end());
        int k=0;
        for(int i=0;i<=nums.size()-1;i++){
            if(nums[i]!=k){
                return k;
            }
                
            k++;
        }
        return nums.size();
    }
};