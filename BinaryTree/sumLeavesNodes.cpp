/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
   int sumofLeaves(TreeNode *root){
       if(root == NULL){
           return 0;
       }
       if(root -> left == NULL && root -> right == NULL){
           return 0;
       }
       int ans = 0;
       if(root -> left && root  -> left -> left == NULL && root -> left  -> right == NULL){
           ans += root->val;
       }
       int leftAns = sumofLeaves(root->left);
       int rightAns = sumofLeaves(root->right);
       return ans + leftAns + rightAns;
   }
};