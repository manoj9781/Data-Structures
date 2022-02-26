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
// //     return head;
// // }

// // int main(){
// //     Node *head;
// //     Node *tail;
// //     Node *temp;
// //     int n, i;
// //     cout << "Enter Number of Nodes " << endl;
// //     cin >> n;
// //     for (i = 0; i < n; i++){
// //         if(i == 0){
// //             head = getNode();
// //             head->next = head;
// //             tail = head;
// //         }
// //         else{
// //             temp = getNode();
// //             tail->next = temp;
// //             temp->next = head;
// //             tail = temp;
// //         }
// //     }
// //     cout << "Input List" << endl;
// //     print(head);
// //     cout << "Enter Element for add at the end" << endl;
// //     addAtEnd(head);
// //     print(head);
// //     cout << "List after delete at end" << endl;
// //     deleteAtEnd(head);
// //     print(head);
// //     search(head);
// //     head =  deleteFirst(head);
// //     cout << "List after delete at first " << endl;
// //     print(head);
// // }

// #include <bits/stdc++.h>

// using namespace std;
// int main()
// {
//     vector<int> ans;
//     int element;
//     cin >> element;
//     while (element > 0)
//     {
//         ans.push_back(element);
//         cin >> element;
//     }
//     int sum = 0;
//     int j = 0;
//     for (int i = 0; i < ans.size(); i++){
//         if(ans[i] < 100 && sum < 100){
//             sum += ans[i];

//         }
//         else{
//             ans[j++] = ans[i];
//         }
//     }

//         for (int i = 0; i < ans.size(); i++)
//         {
//             cout << ans[i] << endl;
//         }
// }

// #include <bits/stdc++.h>

// using namespace std;
// void print(vector<int> ans){
//     for (int i = 0; i < ans.size(); i++){
//         cout << ans[i] << " ";
//     }
//     cout << endl;
// }

// void sub(vector<int> input, int index, vector<int> ans){
//     if(index >=  input.size()){
//         print(ans);
//         return;
//     }
//     ans.push_back(input[index]);
//     sub(input, index + 1, ans);
//     ans.pop_back();
//     sub(input, index + 1, ans);
// }

// int max(vector<int> input)
// {
//     sort(input.begin(), input.end());
//     input.erase(unique(input.begin(), input.end()), input.end());
//     // set<int> s(input.begin(), input.end());
//     // input.assign(s.begin(), s.end());
//     vector<int> ans;
//     ans.reserve(input.size());
//     for (const auto &a : input)
//     {
//         if (a > 0)
//         {
//             ans.push_back(a);
//         }
//     }
//     if (ans.size() == 0 || ans.at(0) != 1)
//     {
//         return 1;
//     }
//     if (ans.size() == 1)
//     {
//         return (ans.at(0) != 1 ? 1 : 2);
//     }
//     for (int i = 0; i < ans.size(); i++)
//     {
//         if (ans.at(i) != i + 1)
//         {
//             return ans.at(i - 1) + 1;
//         }
//     }
//     return ans.back() + 1;
// }

// int main()
// {
//     vector<int> input;
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         int a;
//         cin >> a;
//         input.push_back(a);
//     }

//     vector<int> ans;
//     sub(input, 0, ans);
// }

// #include <bits/stdc++.h>
// using namespace std;

// string findRollOut(string s, vector<int> arr)
// {
//     int n = arr.size();
//     vector<int> brr(n + 1, 0);
//     for (int i = 0; i < n; i++)
//     {
//         brr[0] += 1;
//         brr[arr[i]] -= 1;
//     }
//     for (int i = 1; i < n; i++)
//     {
//         brr[i] += brr[i - 1];
//     }
//     char ch[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
//     for (int i = 0; i < n; i++)
//     {
//         int x = brr[i] % 26;
//         int y = s[i] - 97;
//         s[i] = ch[(x + y) % 26];
//     }
//     return s;
// }

// int main()
// {
//     string s = "abz";

//     vector<int> roll;
//     int n;
//     cout << "Enter size" << endl;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         int a;
//         cin >> a;
//         roll.push_back(a);
//     }

//     string res = findRollOut(s, roll);
//     cout << "Res "<< res << endl;

//     return 0;
// }
