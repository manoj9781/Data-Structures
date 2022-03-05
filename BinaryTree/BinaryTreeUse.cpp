#include <iostream>
#include "BinaryTree.h"
using namespace std;

BinaryTreeNode<int> *input()
{
    int data;
    cout << "Enter Data" << endl;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);
    BinaryTreeNode<int> *leftChild = input();
    BinaryTreeNode<int> *rightChild = input();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

void printTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ":";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data << ",";
    }
    if (root->right != NULL)
    {
        cout << "R" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}
#include <queue>

BinaryTreeNode<int> *inputLevelWise()
{
    int rootData;
    cout << "Enter root Data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left Child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }
        cout << "Enter right Child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            front->right = rightChild;
            pendingNodes.push(front->right);
        }
    }
    return root;
}

void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        if (front->left != NULL)
        {
            cout << "L" << front->left->data << ",";
            pendingNodes.push(front->left);
        }
        if (front->right != NULL)
        {
            cout << "R" << front->right->data;
            pendingNodes.push(front->right);
        }
        cout << endl;
    }
}

class BST
{
private:
    BinaryTreeNode<int> *root;
    bool hasData(BinaryTreeNode<int> *node, int data)
    {
        if (node == NULL)
        {
            return false;
        }
        if (node->data == data)
        {
            return true;
        }
        if (data < node->data)
        {
            return hasData(node->left, data);
        }
        else
        {
            return hasData(node->right, data);
        }
    }

    BinaryTreeNode<int> *insert(BinaryTreeNode<int> *node, int data)
    {
        if (node == NULL)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if (data < node->data)
        {
            node->left = insert(node->left, data);
        }
        else
        {
            node->right = insert(node->right, data);
        }
        return node;
    }

    BinaryTreeNode<int> *deleteNode(BinaryTreeNode<int> *node, int data)
    {
        if (node == NULL)
        {
            return NULL;
        }
        if (data < node->data)
        {
            node->left = deleteNode(node->left, data);
            return node;
        }
        else if (data > node->data)
        {
            node->right = deleteNode(node->right, data);
        }
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            else if (node->left == NULL)
            {
                BinaryTreeNode<int> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                BinaryTreeNode<int> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else
            {
                BinaryTreeNode<int> *minNode = node->right;
                while (minNode->left != NULL)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = deleteNode(node->right, rightMin);
                return node;
            }
        }
        return node;
    }

    void printLevelWise(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            return;
        }
        queue<BinaryTreeNode<int> *> pendingNodes;
        pendingNodes.push(root);
        while (pendingNodes.size() != 0)
        {
            BinaryTreeNode<int> *front = pendingNodes.front();
            pendingNodes.pop();
            cout << front->data << ":";
            if (front->left != NULL)
            {
                cout << "L" << front->left->data << ",";
                pendingNodes.push(front->left);
            }
            if (front->right != NULL)
            {
                cout << "R" << front->right->data;
                pendingNodes.push(front->right);
            }
            cout << endl;
        }
    }

    void printTree(BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return;
        }
        cout << node->data << ":";
        if (node->left != NULL)
        {
            cout << "L" << node->left->data << ",";
        }
        if (node->right != NULL)
        {
            cout << "R" << node->right->data;
        }
        cout << endl;
        printTree(node->left);
        printTree(node->right);
    }

public:
    BST()
    {
        cout << "Contrctor" << endl;
        root = NULL;
    }
    ~BST()
    {
        cout << "Destructor" << endl;
        delete root;
    }
    bool hasData(int data)
    {
        return hasData(root, data);
    }
    void insert(int data)
    {
        this->root = insert(this->root, data);
    }
    void print()
    {
        printLevelWise(this->root);
    }

    void deleteNode(int data)
    {
        this->root = deleteNode(this->root, data);
    }
};

int main()
{
    BST b;
    b.insert(10);
    b.insert(5);
    b.insert(7);
    b.insert(20);
    b.insert(30);
    b.insert(25);
    b.print();
}
