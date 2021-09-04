/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> set;
        while(head != NULL){
            if(set.find(head) != set.end()){
                return head;
            }
            else{
                set.insert(head);
                head = head -> next;
            }
        }
        return NULL;
    }
};