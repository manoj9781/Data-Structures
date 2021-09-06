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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode *> pendingNodes;
        int flag = false;
        pendingNodes.push(root);
        while(pendingNodes.size() != 0){
            int n = pendingNodes.size();
            vector<int> v;
            for(int i = 0; i < n; i++){
                TreeNode *front = pendingNodes.front();
                pendingNodes.pop();
                v.push_back(front -> val);
                if(front -> left != NULL){
                    pendingNodes.push(front -> left);
                }
                if(front -> right != NULL){
                    pendingNodes.push(front -> right);
                }
            }
            if(flag){
                    reverse(v.begin(), v.end());
                }
            flag = !flag;
            ans.push_back(v);
        }
        return ans;
    }
};