77. Combinations
Medium

2892

96

Add to List

Share
Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

You may return the answer in any order.

 

Example 1:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
Example 2:

Input: n = 1, k = 1
Output: [[1]]
 

Constraints:

1 <= n <= 20
1 <= k <= n

class Solution {
public:
    
    void combine(int start, int k, vector<vector<int>> &ans, vector<int> &temp, int n){
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }
        for(int i = start; i <= n; i++){
            temp.push_back(i);
            combine(i+1, k, ans, temp, n);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
      vector<vector<int>> ans;
        vector<int> temp;
        combine(1, k, ans, temp, n);
        return ans;
       
    }
};