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

int main()
{
    cout << "Enter value for linked list" << endl;
    Node *head = takeInputBetter();
    print(head);
    head = removeDuplicates(head);
    print(head);
}