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
    TreeNode* getTargetCopy(TreeNode* root, TreeNode* cloned, TreeNode* target) {
        if(root == NULL){
            return NULL;
        }
        
        queue<TreeNode *>pendingNodes, clonedNodes;
        clonedNodes.push(cloned);
        pendingNodes.push(root);
        while(pendingNodes.size() != 0){
           TreeNode *front = pendingNodes.front();
            TreeNode *clonedFront = clonedNodes.front();
            clonedNodes.pop();
            pendingNodes.pop();
            if(target -> val == clonedFront -> val){
                return clonedFront;
            }
            if(front -> left != NULL){
                pendingNodes.push(front -> left);
                clonedNodes.push(clonedFront -> left);
            }
            if(front -> right != NULL){
                pendingNodes.push(front -> right);
                clonedNodes.push(clonedFront -> right);
            }
        }
        return NULL;
    }
};