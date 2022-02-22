#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    unordered_map<int, int> m_inorderMap;
    int m_preorderIndex;

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {

        TreeNode *root = NULL;
        if (preorder.size() == 0)
            return root;

        for (int i = 0; i < inorder.size(); ++i)
            m_inorderMap[inorder[i]] = i;

        m_preorderIndex = 0;

        return buildSubtree(preorder, inorder, 0, inorder.size() - 1);
    }

    TreeNode *buildSubtree(const vector<int> &preorder, const vector<int> &inorder, int inorderLeft, int inorderRight)
    {
        if (inorderLeft > inorderRight)
            return NULL;

        TreeNode *root = new TreeNode(preorder[m_preorderIndex++]);

        int rootIndex = m_inorderMap[root->val];

        root->left = buildSubtree(preorder, inorder, inorderLeft, rootIndex - 1);
        root->right = buildSubtree(preorder, inorder, rootIndex + 1, inorderRight);

        return root;
    }
};