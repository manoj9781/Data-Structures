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
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == NULL)
        {
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode *> pendingNodes;
        pendingNodes.push(root);
        ans.push_back({root->val});
        while (pendingNodes.size() != 0)
        {
            int size = pendingNodes.size();
            vector<int> v;
            for (int i = 0; i < size; i++)
            {
                TreeNode *front = pendingNodes.front();
                pendingNodes.pop();

                if (front->left != NULL)
                {
                    pendingNodes.push(front->left);
                    v.push_back(front->left->val);
                }
                if (front->right != NULL)
                {
                    pendingNodes.push(front->right);
                    v.push_back(front->right->val);
                }
            }

            if (v.size() > 0)
            {
                ans.push_back(v);
            }
        }
        return ans;
    }
};