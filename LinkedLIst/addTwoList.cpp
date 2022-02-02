/**
 * Definition for singly-linked list.
 * 
 */

#include<iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    
    ListNode *add(ListNode *head1, ListNode* head2){
        int carry = 0;
        ListNode *head = NULL;
        ListNode *tail = NULL;
        while(head1 != NULL || head2 != NULL || carry != 0){
            int data1 = 0;
            if(head1 != NULL){
                data1 = head1 -> val;
            }
            int data2 = 0;
            if(head2 != NULL){
                data2 = head2 -> val;
            }
            int sum = data1 + data2 + carry;
            int digit = sum % 10;
            ListNode *newNode = new ListNode(digit);
            if(head == NULL){
                head = newNode;
                tail = newNode;
            }
            else{
                tail -> next = newNode;
                tail = newNode;
            }
            carry = sum/10;
            if(head1 != NULL){
                head1 = head1 -> next;
            }
            if(head2 != NULL){
                head2 = head2 -> next;
            }
        }
        return head;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = add(l1, l2);
        return ans;
    }
};


// Second Variation of this question


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
    
    ListNode *reverse(ListNode *head){
        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode *temp = reverse(head -> next);
        ListNode *ans = head -> next;
        ans -> next = head;
        head -> next = NULL;
        return temp;
    }
    
     ListNode *add(ListNode *head1, ListNode* head2){
        int carry = 0;
        ListNode *head = NULL;
        ListNode *tail = NULL;
        while(head1 != NULL || head2 != NULL || carry != 0){
            int data1 = 0;
            if(head1 != NULL){
                data1 = head1 -> val;
            }
            int data2 = 0;
            if(head2 != NULL){
                data2 = head2 -> val;
            }
            int sum = data1 + data2 + carry;
            int digit = sum % 10;
            ListNode *newNode = new ListNode(digit);
            if(head == NULL){
                head = newNode;
                tail = newNode;
            }
            else{
                tail -> next = newNode;
                tail = newNode;
            }
            carry = sum/10;
            if(head1 != NULL){
                head1 = head1 -> next;
            }
            if(head2 != NULL){
                head2 = head2 -> next;
            }
        }
        return head;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        ListNode *ans = add(l1, l2);
        ans = reverse(ans);
        return ans;
        
    }
};