378. Kth Smallest Element in a Sorted Matrix
Medium

4707

209

Add to List

Share
Given an n x n matrix where each of the rows and columns are sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

 

Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
Example 2:

Input: matrix = [[-5]], k = 1
Output: -5
 

Constraints:

n == matrix.length
n == matrix[i].length
1 <= n <= 300
-109 <= matrix[i][j] <= 109
All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
1 <= k <= n2

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        priority_queue<int> p;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                p.push(matrix[i][j]);
            }
        }
        while(p.size() > k){
            p.pop();
        }
        return p.top();
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n-1][n-1];
        
        while(left <= right){
            int mid = left + (right-left)/2;
            int num = 0;
            
            for (int i = 0; i < n; ++i){
                int pos = upper_bound(begin(matrix[i]), end(matrix[i]), mid) - begin(matrix[i]);
                num += pos;
            }
            
            if (num < k){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return left;
    }
};