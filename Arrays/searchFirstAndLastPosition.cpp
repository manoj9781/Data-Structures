class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() <1)
            return {-1,-1};
        vector<int> out;
        int n = nums.size()-1;
        int l =0;
        int r = n;
       
        while(l<=r) {
             int mid = l+ (r-l)/2;
            if(nums[mid] == target) {
                int beg = mid;
                int end = mid;
                while(beg-1 >=0 && nums[beg-1] == target) beg--;
                while(end+1 <=n && nums[end+1] == target) end++;
                out.push_back(beg);
                out.push_back(end);
                return out;
            }
            else if(target > nums[mid]){
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        out.push_back(-1);
        out.push_back(-1);
        return out;
    }
};