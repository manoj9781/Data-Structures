
#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxSum = 0;
        int size = nums.size();
        for(int i = 0; i < k; i++){
         maxSum += nums[i];   
        }
        int windowSum = maxSum;
        for(int j = k; j < size; j++){
            windowSum += nums[j] - nums[j-k];
            maxSum = max(windowSum, maxSum);
        }
        cout << maxSum <<endl;
        double ans = double(maxSum) / k;
        return ans;
    }
};