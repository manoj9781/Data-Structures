class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // unordered_map<int, int> map;
        // vector<int> ans;
        // for(int i = 0; i < numbers.size(); i++){
        //     if(map.find(target-numbers[i]) != map.end()){
        //         int value = map[target-numbers[i]];
        //         ans.push_back(value + 1);
        //         ans.push_back(i +1);
        //     }
        //     map[numbers[i]] = i;
        // }
        // return ans;
        
        int i = 0;
        int j = numbers.size() - 1;
        while(i < j){
            int sum = numbers[i] + numbers[j];
            if(sum == target){
                return {i+1, j+1};
            }
            else if(sum < target){
                i++;
            }
            else {
                j--;
            }
        }
        return {};
    }
};