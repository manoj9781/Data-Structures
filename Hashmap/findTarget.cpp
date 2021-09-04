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
    void inOrder(TreeNode *root, vector<int> &ans){
        if(root == NULL){
            return;
        }
        
        inOrder(root -> left, ans);
        ans.push_back(root ->val);
        inOrder(root -> right, ans);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        inOrder(root, ans);
        unordered_map<int, int> map;
        for(int i = 0; i < ans.size(); i++){
            if(map.find(k-ans[i]) != map.end()){
                return true;
            }
            else{
                map[ans[i]] = i;
            }
        }
        return false;
        
    }
};