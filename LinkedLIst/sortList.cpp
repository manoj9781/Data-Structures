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
    ListNode* sortList(ListNode* head) {
        if(head == NULL){
            return head;
        }
        
        vector<int> ans;
        ListNode *temp = head;
        while(temp!= NULL){
            ans.push_back(temp -> val);
            temp = temp -> next;
        }
       sort(ans.begin(), ans.end());
        head = NULL;
        ListNode *tail = NULL;
        for(int i = 0; i < ans.size(); i++){
            ListNode *newNode = new ListNode(ans[i]);
            if(head == NULL){
                head = newNode;
                tail = newNode;
            }
            else{
                tail -> next = newNode;
                tail = tail -> next;
            }
        }
        return head;
    }
};