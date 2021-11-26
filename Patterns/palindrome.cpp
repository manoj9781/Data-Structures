9. Palindrome Number
Easy

4452

1921

Add to List

Share
Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.

 

Example 1:

Input: x = 121
Output: true
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Example 4:

Input: x = -101
Output: false
 

Constraints:

-231 <= x <= 231 - 1

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        int n = x;
        int ans = 0;
        while(n != 0){
            int rem = n %10;
            if((ans > INT_MAX/10) || (ans < INT_MIN/10)){
              return false;
            }
             ans = (ans *10) + rem; 
            n = n/10;
        }
        if(ans == x){
            return true;
        }
        return false;
    }
};