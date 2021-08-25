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
    ListNode* rotateRight(ListNode* head, int k) {
       if(head == NULL || head -> next == NULL){
           return head;
       }
        
        ListNode *temp = head;
        int length = 1;
        while(temp -> next != NULL){
            length++;
            temp  =temp -> next;
        }
        temp -> next = head;
        int position = length - k % length;
        for(int i = 0; i < position; i++){
            temp = temp -> next;
        }
        head = temp -> next;
        temp -> next = NULL;
        return head;
       
    }
};