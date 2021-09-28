70. Climbing Stairs
Easy

8263

241

Add to List

Share
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45

  int climbStairs(int n) {
        if(n == 0 || n== 1){
            return 1;
        }
        else if(n == 2){
            return 2;
        }
        else{
            return climbStairs(n-2) + climbStairs(n-1);
        }
  }


class Solution {
public:
    int climbStairs(int n) {
        
        int ans[n+1];
        ans[0] = 1;
        ans[1] = 1;
        // ans[2] = 2;
        for(int i = 2; i <= n; i++){
            ans[i] = ans[i-1] + ans[i-2];
        }
        return ans[n];
    }
};