/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* getTargetCopy(TreeNode *root, TreeNode *target){
        if(root == NULL){
            return NULL;
        }
        if(root -> val == target -> val){
            return root;
        }
        TreeNode *leftAns = getTargetCopy(root -> left, target);
        TreeNode *rightAns = getTargetCopy(root -> right, target);
        if(leftAns != NULL){
            return leftAns;
        }
        else if(rightAns != NULL){
            return rightAns;
        }
        return NULL;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return getTargetCopy(cloned, target);
    }
};