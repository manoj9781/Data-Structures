
 // Definition for singly-linked list.
  struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head -> next == NULL){
            return NULL;
        }
        ListNode *temp = head;
        int i = 0;
        while(temp != NULL){
            temp = temp -> next;
            i++;
        }
        int point = i - n;
        int j = 0;
        if(point == j){
            return head -> next;
        }
        temp = head;
        while(temp != NULL && j < point-1  ){
            temp = temp -> next;
            j++;
        }
        if(temp -> next != NULL){
            temp -> next = temp -> next -> next;
        }
        return head;
    }
};