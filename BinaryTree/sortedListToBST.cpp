/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
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
    
    TreeNode *constructBST(vector<int> ans, int start, int end){
        if(start > end){
            return NULL;
        }
        int mid = (start + end)/2;
        TreeNode *root = new TreeNode(ans[mid]);
        root -> left = constructBST(ans, start, mid -1);
        root -> right = constructBST(ans, mid +1, end);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> ans;
        ListNode *temp = head;
        while(temp != NULL){
            ans.push_back(temp -> val);
            temp = temp -> next;
        }
        return constructBST(ans, 0, ans.size() -1);
    }
};

TreeNode *SortedList(ListNode *head){
    if(head == NULL){
        return 0;
    }
    if(head -> next == NULL){
        return new TreeNode(head->val);
    }
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *pre = NULL;
    while(fast != NULL && fast -> next != NULL){
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    TreeNode *root = new TreeNode(slow->val);
    pre->next = NULL;
    root->left = SortedList(head);
    root->right = SortedList(slow->next);
    return root;
}