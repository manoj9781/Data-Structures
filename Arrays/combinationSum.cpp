#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    
  void combinationSumHelper(vector<vector<int>>& ans, vector<int> v, vector<int>candidates, int target, int start){
     
      if(target == 0){
          ans.push_back(v);
      }
       if(target < 0){
          return;
      }
      for(int i = start; i < candidates.size();i++){
          if(candidates[i] <= target){
              v.push_back(candidates[i]);
              combinationSumHelper(ans, v, candidates, target - candidates[i], i );
              v.pop_back();
          }
          else{
              break;
          }
      }
      return;
  }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        combinationSumHelper(ans, v, candidates, target, 0 );
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        if(n < 3){
           return result;
        }
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i< n-2;i++){
            if(i == 0 || nums[i] != nums[i-1] ){
                int j=i+1;
                int k = n-1;
                while(j < k){
                    int sum = nums[i] +nums[j] +nums[k];
                    if(sum == 0){
                        result.push_back({nums[i], nums[j], nums[k]});
                        while(j < k && nums[j] == nums[j+1])
                            j++;
                        while(j < k && nums[k] == nums[k-1])
                            k--;
                        j++;
                        k--;
                    }
                    else if( sum > 0){
                        k--;
                    }
                    else{
                        j++;
                    }
                }
            }
        }
        return result;
        
    }
};