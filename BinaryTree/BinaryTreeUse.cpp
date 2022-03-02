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
#include<queue>

BinaryTreeNode<int> *inputLevelWise(){
    int rootData;
    cout << "Enter root Data" << endl;
    cin >> rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left Child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1){
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }
        cout << "Enter right Child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if(rightChildData != -1){
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            front->right = rightChild;
            pendingNodes.push(front->right);
        }
    }
    return root;
}

void printLevelWise(BinaryTreeNode<int> *root){
    if(root == NULL){
        return;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        if(front -> left != NULL){
            cout << "L" << front->left->data << ",";
            pendingNodes.push(front->left);
        }
        if(front -> right !=  NULL){
            cout << "R" << front->right->data;
            pendingNodes.push(front->right);
        }
        cout << endl;
    }
}

int main()
{
    // BinaryTreeNode<int> *root = input();
    BinaryTreeNode<int> *root = inputLevelWise();
    printLevelWise(root);
    // printTree(root);
}