#include <iostream>
#include "tree.h"
using namespace std;

TreeNode<int> *takeInput()
{
    int data;
    cout << "Enter data" << endl;
    cin >> data;
    TreeNode<int> *root = new TreeNode<int>(data);
    int n;
    cout << "Enter Number of child" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

#include<queue>
TreeNode<int> *inputLevelWise(){
    int rootData;
    cout << "Enter root Data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter number of child " << front->data << endl;
        int n;
        cin >>n ;
        for (int i = 0; i < n; i++){
            cout << "Enter " << i << "th child of " << front->data << endl;
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(front->children[i]);
        }
    }
    return root;
}

void PrintLevelWise(TreeNode<int> *root){
    if(root == NULL){
        return;
    }
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        int size = pendingNodes.size();
         TreeNode<int> *front = pendingNodes.front();
         pendingNodes.pop();
         cout << front->data << ":";
         for (int i = 0; i < front->children.size(); i++)
         {
             cout << front->children[i]->data << ",";
             pendingNodes.push(front->children[i]);
         }
         cout << endl;
    }
}

int countNodes(TreeNode<int> *root){
    if(root == NULL){
        return 0;
    }
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++){
        ans += countNodes(root->children[i]);
    }
    return ans;
}

// 1 2 2 3 2 4 5 2 6 7 0 0 0 0 
int main()
{
    TreeNode<int> *root = inputLevelWise();
    // printTree(root);
    PrintLevelWise(root);
    cout << "Count Nodes" << countNodes(root) << endl;
    delete root;
}