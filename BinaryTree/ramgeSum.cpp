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
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL){
            return 0;
        }
        
        queue<TreeNode *> pendingNodes;
        pendingNodes.push(root);
        int sum = 0;
        while(pendingNodes.size() != 0){
            TreeNode *front = pendingNodes.front();
            pendingNodes.pop();
            if(front -> val >= low && front -> val <=high){
                sum += front -> val;
            }
            if(front -> left != NULL){
                pendingNodes.push(front ->left);
            }
            if(front -> right != NULL){
                pendingNodes.push(front -> right);
            }
        }
        return sum;
    }
};