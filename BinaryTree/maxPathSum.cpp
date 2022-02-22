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
    
    int maxPath(TreeNode *root, int &maximum){
        if(root == NULL){
            return 0;
        }
        int leftAns = max(0, maxPath(root -> left, maximum));
        int rightAns = max(0, maxPath(root -> right, maximum));
        maximum = max(maximum, leftAns+rightAns+ root -> val);
        return root -> val + max(leftAns, rightAns);
    }
    int maxPathSum(TreeNode* root) {
        int maximum = INT_MIN;
        maxPath(root, maximum);
        return maximum;
    }
};