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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        queue<TreeNode *> pendingNodes;
        pendingNodes.push(root);
        while(pendingNodes.size() != 0){
            int size = pendingNodes.size();
            for(int i = 1; i <= size; i++){
                TreeNode *front = pendingNodes.front();
                pendingNodes.pop();
                if(i == size){
                    ans.push_back(front -> val);
                }
                if(front -> left != NULL){
                    pendingNodes.push(front -> left);
                }
                if(front -> right != NULL){
                    pendingNodes.push(front -> right);
                }
            }
        }
        return ans;
    }
};

void rightView(TreeNode *root, int level, vector<int> ans){
    if(root == NULL){
        return;
    }
    if(level == ans.size()){
        ans.push_back(root->val);
    }
    rightView(root->right, level + 1, ans);
    rightView(root->left, level + 1, ans);
}

vector<int> rightSideView(TreeNode *root){
    if(root == NULL){
        return {};
    }
    vector<int> ans;
    void rightView(root, 0, ans);
    return ans;
}