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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        queue<TreeNode *>pendingNodes;
        pendingNodes.push(root);
        while(pendingNodes.size() != 0){
            int size = pendingNodes.size();
            int max = INT_MIN;
            for(int i = 0; i < size; i++){
                TreeNode * front = pendingNodes.front();
                pendingNodes.pop();
                if(front -> val > max){
                    max = front -> val;
                }
                if(front -> left != NULL){
                    pendingNodes.push(front -> left);
                }
                if(front -> right != NULL){
                    pendingNodes.push(front -> right);
                }
            }
             ans.push_back(max);
        }
        return ans;
    }
};