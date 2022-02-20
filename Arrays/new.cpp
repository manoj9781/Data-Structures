// #include<iostream>
// using namespace std;

// class Node{
//     public:
//         int data;
//         Node *next;
//         Node(int data){
//             this->data = data;
//             next = NULL;
//         }
// };

// Node *getNode(){
//     int data;
//     cout << "Enter Data " << endl;
//     cin >> data;
//     Node *newNode = new Node(data);
//     return newNode;
// }

// void print(Node *head){
//     if(head == NULL){
//         cout << "List is Empty" << endl;
//     }
//     else{
//         Node *temp = head;
//         while(temp ->next != head){
//             cout << temp->data << " ";
//             temp = temp->next;
//         }

//         cout << temp->data << " ";
//     }
//     cout << endl;
// }

// // Insertion at the End

// void addAtEnd(Node *head){
//     Node *newNode  = getNode();
//     Node *temp = head;
//     while(temp -> next != head){
//         temp = temp->next;
//     }
//     temp->next = newNode;
//     newNode->next = head;
// }

// // Delete from End

// void deleteAtEnd(Node *head){
//     Node *q = head;
//     Node *temp;
//     while(1){
//         temp = q->next;
//         if(temp -> next != head){
//             q = q->next;
//         }
//         else{
//             break;
//         }
//     }
//     q->next = head;
//     delete temp;
// }

// //Search an element

// void search(Node *head){
//     if(head == NULL){
//         cout << "List is empty" << endl;
//     }
//     bool ans = false;
//     int num;
//     Node *temp = head;
//     cout << "Enter element for search" << endl;
//     cin >> num;
//     while(temp -> next != head){
//         if(temp -> data == num){
//             cout << "Element found" << endl;
//             ans = true;
//             break;
//         }
//         temp = temp->next;
//     }
//     if(ans == false){
//         cout << "Element not found" << endl;
//         return;
//     }
// }

// // Deletion at the begining

//  Node *deleteFirst(Node *head)
// {
//     Node *temp = head;
//     while(temp -> next != head){
//         temp = temp->next;
//     }
//     temp->next = head->next;
//     Node *ans = head;
//     head = head->next;
//     delete ans;
//     return head;
// }

// int main(){
//     Node *head;
//     Node *tail;
//     Node *temp;
//     int n, i;
//     cout << "Enter Number of Nodes " << endl;
//     cin >> n;
//     for (i = 0; i < n; i++){
//         if(i == 0){
//             head = getNode();
//             head->next = head;
//             tail = head;
//         }
//         else{
//             temp = getNode();
//             tail->next = temp;
//             temp->next = head;
//             tail = temp;
//         }
//     }
//     cout << "Input List" << endl;
//     print(head);
//     cout << "Enter Element for add at the end" << endl;
//     addAtEnd(head);
//     print(head);
//     cout << "List after delete at end" << endl;
//     deleteAtEnd(head);
//     print(head);
//     search(head);
//     head =  deleteFirst(head);
//     cout << "List after delete at first" << endl;
//     print(head);
// }

#include <bits/stdc++.h>

using namespace std;
int main()
{
    vector<int> ans;
    int element;
    cin >> element;
    while (element > 0)
    {
        ans.push_back(element);
        cin >> element;
    }
    int sum = 0;
    int j = 0;
    for (int i = 0; i < ans.size(); i++){
        if(ans[i] < 100 && sum < 100){
            sum += ans[i];
            

        }
        else{
            ans[j++] = ans[i];
        }
    }

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << endl;
        }
}