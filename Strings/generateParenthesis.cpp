22. Generate Parentheses
Medium

9857

394

Add to List

Share
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8


class Solution {
public:
    
    void generateParenthesis(string &current, vector<string> &ans, int right, int left){
        if(left == 0 && right == 0){
            ans.push_back(current);
            return;
        }
        if(right > 0){
            current.push_back('(');
            generateParenthesis(current, ans, right - 1, left);
            current.pop_back();
        }
        if(right < left && left > 0){
            current.push_back(')');
            generateParenthesis(current, ans, right, left -1);
            current.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        string current;
        vector<string> ans;
        generateParenthesis(current, ans, n, n);
        return ans;
    }
};
