#include <iostream>
#include <vector>
#include <climits>
#include <stack>
using namespace std;
//  Definition for a binary tree node.
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
public:
    TreeNode *contruct(vector<int> &nums, int start, int end)
    {
        if (start >= end)
        {
            return NULL;
        }

        int maximum = INT_MIN;
        int maximumIndex = -1;
        for (int i = start; i < end; i++)
        {
            if (nums[i] > maximum)
            {
                maximum = nums[i];
                maximumIndex = i;
            }
        }
        TreeNode *root = new TreeNode(maximum);
        root->left = contruct(nums, start, maximumIndex);
        root->right = contruct(nums, maximumIndex + 1, end);
        return root;
    }

    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return contruct(nums, 0, nums.size());
    }
};

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
    TreeNode *insertIntoMaxTree(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            return new TreeNode(val);
        }

        if (val > root->val)
        {
            return new TreeNode(val, root, NULL);
        }
        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
};

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
   void flatten(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    stack<TreeNode*> stk;
    stk.push(root);
    while (stk.size() != 0)
    {
        TreeNode *top = stk.top();
        stk.pop();
        if (top->right != NULL)
        {
            stk.push(top->right);
        }
        if (top->left != NULL)
        {
            stk.push(top->left);
        }

        if (stk.size() != 0)
        {
            top->right = stk.top();
        }
        top->left = NULL;
    }
}

};