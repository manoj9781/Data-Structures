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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        queue<TreeNode *> pendingNodes;
        pendingNodes.push(root);
        vector<vector<int>> ans;
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
            ans.push_back(v);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};