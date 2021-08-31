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