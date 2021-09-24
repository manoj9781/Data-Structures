234. Palindrome Linked List
Easy

6498

476

Add to List

Share
Given the head of a singly linked list, return true if it is a palindrome.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9

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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return true;
        }
        ListNode *temp = head;
        stack<int> pendingNodes;
        while(temp != NULL){
            pendingNodes.push(temp -> val);
            temp = temp -> next;
        }
        
        temp = head;
        while(temp != NULL){
            int top = pendingNodes.top();
            pendingNodes.pop();
            if(top != temp -> val){
                return false;
            }
            temp = temp -> next;
        }
        return true;
    }
};