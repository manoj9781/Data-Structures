#include <iostream>
using namespace std;

#include "BinaryTree.h"

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

int main()
{
    BinaryTreeNode<int> *root = input();
    printTree(root);
}