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

int sum(TreeNode<int> *root){
    if(root == NULL){
        return 0;
    }
    int ans = root->data;
    for (int i = 0; i < root->children.size(); i++){
        ans += sum(root->children[i]);
    }
    return ans;
}

TreeNode<int> *max(TreeNode<int> *root){
    if(root == NULL){
        return NULL;
    }
    TreeNode<int> *maximum = root;
    for (int i = 0; i < root->children.size(); i++){
        TreeNode<int> *temp = max(root->children[i]);
        if(temp -> data > maximum -> data){
            maximum = temp;
        }
    }
    return maximum;
}

int getHeight(TreeNode<int> *root){
    if(root == NULL){
        return 0;
    }
    int height = 0;
    for (int i = 0; i < root->children.size(); i++){
        int ans = getHeight(root->children[i]);
        if(ans > height){
            height = ans;
        }
    }
    return height + 1;
}

void printAtLevelK(TreeNode<int> *root, int k){
    if(root == NULL){
        return ;
    }
    if(k == 0){
        cout << root->data<< " ";
    }
    for (int i = 0; i < root->children.size(); i++){
        printAtLevelK(root->children[i], k - 1);
    }
}


int countLeafNodes(TreeNode<int> *root){
    if(root == NULL){
        return 0;
    }
    if(root ->children.size() == 0){
        return 1;
    }
    int ans = 0;
    for (int i = 0; i < root->children.size(); i++){
        ans += countLeafNodes(root->children[i]);
    }
    return ans;
}
// 1 2 2 3 2 4 5 2 6 7 0 0 0 0 
int main()
{
    TreeNode<int> *root = inputLevelWise();
    cout << "Count Nodes " << countNodes(root) << endl;
    cout << "Sum of Nodes " << sum(root) << endl;
    TreeNode<int> *ans = max(root);
    cout << "Max Node " << ans->data << endl;
    cout << "Height " << getHeight(root) << endl;
    cout << "Print At level K " << endl;
    printAtLevelK(root, 1);
    cout << endl;
    cout << "Leaves Node " << countLeafNodes(root) << endl;
    delete root;
}