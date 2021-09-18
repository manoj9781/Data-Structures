class Solution {
public:
    // int minimumTotal(vector<vector<int>>& triangle) {
    //  int sum = 0;
    //     for(int i = 0; i <triangle.size(); i++ ){
    //          int min = INT_MAX;
    //         for(int j = 0; j < triangle[i].size(); j++){
    //             if(triangle[i][j] < min){
    //                 min = triangle[i][j];
    //             }
    //         }
    //          sum += min;
    //     }
    //    return sum; 
    // }
    
      int minimumTotal(vector<vector<int>> &nums){
          for(int i = nums.size() -2; i >= 0; i--){
              for(int j = 0; j < nums[i].size(); j++){
                  nums[i][j] += min(nums[i+1][j], nums[i+1][j+1]);
              }
          }
          return nums[0][0];
      }
};