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
    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int sum = 0;
        queue<TreeNode *> pendingNodes;
        pendingNodes.push(root);
        while(pendingNodes.size() != 0){
            int levelSum = 0;
            int size = pendingNodes.size();
            for(int i = 0; i < size; i++){
                TreeNode *front = pendingNodes.front();
                pendingNodes.pop();
                levelSum += front -> val;
                if(front -> left != NULL){
                    pendingNodes.push(front -> left);
                }
                if(front -> right != NULL){
                    pendingNodes.push(front -> right);
                }
            }
            if(pendingNodes.size() == 0){
                sum = levelSum;
            }
        }
        return sum;
    }
};