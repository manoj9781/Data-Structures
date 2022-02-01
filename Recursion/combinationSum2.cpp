class Solution {
public:
    void combinationSum2(int index, int target, vector<vector<int>> &ans, vector<int> &result, vector<int> &input){
        if(target == 0){
            ans.push_back(result);
            return;
        }
        for(int i = index; i < input.size(); i++){
            if(i > index && input[i] == input[i-1]){
                continue;
            }
             if(input[i] > target){
                 break;
             }
            result.push_back(input[i]);
            combinationSum2(i+1, target-input[i], ans, result, input);
            result.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& input, int target) {
        vector<vector<int>> ans;
        vector<int> result;
        sort(input.begin(), input.end());
        combinationSum2(0, target, ans, result, input);
        return ans;
    }
};