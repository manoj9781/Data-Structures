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
    int sumEvenGrandparent(TreeNode *root){
    if(root == NULL){
        return 0;
    }
    queue<TreeNode *> pendingNodes;
    pendingNodes.push(root);
    int ans = 0;
    while(pendingNodes.size() != 0){
        TreeNode *front = pendingNodes.front();
        if(front -> val %2 == 0){
            TreeNode *temp = front->left;
            if(temp != NULL){
               if(temp -> left != NULL){
                    ans += temp->left->val;
               }
               if(temp -> right != NULL){
                   ans += temp->right->val;
               }
            }
            temp = front->right;
           if(temp != NULL){
               if(temp -> left != NULL){
                   ans += temp->left->val;
               }
               if(temp -> right != NULL){
                   ans += temp ->right->val;
               }
           }
        }
        if(front -> left != NULL){
            pendingNodes.push(front->left);
        }
        if(front -> right != NULL){
            pendingNodes.push(front->right);
        }
        pendingNodes.pop();
    }
    return ans;
}
    
    
};