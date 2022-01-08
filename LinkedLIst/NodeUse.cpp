#include <iostream>
using namespace std;
#include "Node.cpp"

Node *takeInputBetter()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int lenght(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void print(Node *head, int i)
{
    if (head == NULL)
    {
        return;
    }
    if (i == 0)
    {
        cout << head->data;
        return;
    }
    Node *temp = head;
    int count = 0;
    while (temp->next != NULL && count < i)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next != NULL)
    {
        cout << temp->data;
    }
    return;
}

Node *insert(Node *head, int i, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        return newNode;
    }
    if (i == 0)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        return newNode;
    }

    Node *temp = head;
    int count = 0;
    while (temp->next != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next != NULL)
    {
        Node *newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

Node *deleteNode(Node *head, int i)
{
    if (head == NULL)
    {
        return NULL;
    }
    int count = 0;
    Node *temp = head;
    if (i == 0)
    {
        Node *a = head;
        head = head->next;
        delete a;
        return head;
    }
    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        Node *a = temp->next;
        Node *b = a->next;
        temp->next = b;
        delete a;
        return head;
    }
    return head;
}

int lengthRecursive(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int ans = lengthRecursive(head->next);
    return ans + 1;
}

Node *insertNodeRecursive(Node *head, int data, int i)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (i == 0)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        return newNode;
    }

    Node *temp = insertNodeRecursive(head->next, data, i - 1);
    head->next = temp;
    return head;
}

Node *deleteNodeRecursive(Node *head, int i)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (i == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *temp = deleteNodeRecursive(head->next, i - 1);
    head->next = temp;
    return head;
}

int findNode(Node *head, int n)
{
    if (head == NULL)
    {
        return -1;
    }
    int index = -1;
    int flag = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == n)
        {
            return index + 1;
            flag = 1;
        }
        else
        {
            index++;
        }
        temp = temp->next;
    }
    if (flag == 0)
    {
        return -1;
    }
    return index;
}

Node *appendToLast(Node *head, int n){
    if(n == 0 || head == NULL){
        return NULL;
    }
    Node *temp = head;
    Node *slow = head;
    for (int i = 1; i < n -1 ; i++){
        temp = temp->next;
    }
    Node *ans = temp->next;
    while(slow -> next != NULL){
        slow = slow->next;
    }
    slow->next = head;
    temp->next = NULL;
    return ans;
}

Node *removeDuplicates(Node *head){
    if(head == NULL){
        return head;
    }
    Node *temp = head;
    while(temp -> next != NULL){
        if(temp ->data == temp -> next -> data){
            temp->next = temp->next->next;
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}

void reverseList(Node *head){
    if(head == NULL){
        return;
    }
    reverseList(head->next);
    cout << head->data <<" ";
}

#include<stack>

bool isPalindrome(Node *head){
    if(head == NULL || head -> next == NULL){
        return true;
    }
    stack<int> s;
    Node *temp = head;
    while(temp != NULL){
        s.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){
        int top = s.top();
        s.pop();
        if(top != temp -> data){
            return false;
        }
        temp = temp->next;
    }
    return true;
}

Node *midPoint(Node *head){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node *slow = head;
    Node *fast = head->next;
    while(fast != NULL && fast -> next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

 Node* mergeTwoLists(Node* head1, Node* head2) {
        if(head1 == NULL){
            return head2;
        }
        if(head2 == NULL){
            return head1;
        }
        Node *head = NULL;
        Node *tail = NULL;
        
        if(head1  -> data <= head2 -> data){
            head = head1;
            tail = head1;
            head1 = head1 -> next;
        }
        else{
            head = head2;
            tail = head2;
            head2 = head2 -> next;

        }
        
        while(head1 != NULL && head2 != NULL){
            if(head1 -> data <= head2 -> data){
                tail -> next = head1;
                tail = tail -> next;
                head1 = head1 -> next;
            }
            else{
                tail -> next = head2;
                tail = tail -> next;
                head2 = head2 -> next;
            }
        }
        if(head1 == NULL){
            tail -> next = head2;
        }
        if(head2 == NULL){
            tail -> next = head1;
        }
        return head;
    }

Node *mergeSort(Node *head){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node *mid = midPoint(head);
    Node *head2 = mid -> next;
    mid->next = NULL;
    Node *ans = mergeTwoLists(mergeSort(head), mergeSort(head2));
    return ans;
}

class Pair{
    public:
    Node *head;
    Node *tail;
};

Pair reverse(Node *head){
    if(head == NULL || head -> next == NULL){
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallAns = reverse(head->next);
    smallAns.tail->next = head;
    head->next = NULL;

    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;
}

Node *reverseBetter(Node *head){
    return reverse(head).head;
}

int main()
{
    cout << "Enter value for linked list" << endl;
    Node *head = takeInputBetter();
    Node *ans = reverseBetter(head);
    print(ans);
    cout << endl;
}