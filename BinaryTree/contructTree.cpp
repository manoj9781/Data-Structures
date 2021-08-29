#include<iostream>
#include<vector>
#include<climits>
using namespace std;
//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    
    TreeNode * contruct(vector<int>& nums, int start, int end){
        if(start >= end){
            return NULL;
        }
        
        int maximum = INT_MIN;
        int maximumIndex = -1;
        for(int i = start; i< end; i++){
            if(nums[i] > maximum){
                maximum = nums[i];
                maximumIndex = i;
            }
        }
        TreeNode *root = new TreeNode(maximum);
        root -> left = contruct(nums, start, maximumIndex);
        root -> right = contruct(nums, maximumIndex+1, end);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return contruct(nums, 0, nums.size());
    }
};

