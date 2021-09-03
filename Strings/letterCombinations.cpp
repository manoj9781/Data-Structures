class Solution {
public:
    
    void letterCombinations(string digits, vector<string> &v, string nums[], int i, string s){
        if(i == digits.length()){
            v.push_back(s);
            return;
        }
        string val = nums[digits[i] - '0'];
        for(int j = 0; j < val.length(); j++){
            letterCombinations(digits, v, nums, i+1, s+val[j]);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        if(digits.size()== 0){
            return v;
        }
       string s[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        letterCombinations(digits, v, s, 0, "");
        return v;
    }
};