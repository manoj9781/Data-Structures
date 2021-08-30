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
    void reorderList(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return;
        }
        ListNode *temp= head;
        stack<ListNode*> s;
        int i = 0;
        while(temp !=NULL){
            i++;
            s.push(temp);
            temp = temp -> next;
        }
        int len;
        if(i % 2 == 0){
            len = i/2 ;
        }
        else{
             len = i/2 +1;
         }
        temp = head;
       
        while(s.size() > len){
            ListNode *next = temp -> next;
            temp -> next = s.top();
            s.pop();
            temp = temp -> next;
            temp -> next = next;
            temp = temp-> next;
        }
        temp -> next = NULL;
    }
};