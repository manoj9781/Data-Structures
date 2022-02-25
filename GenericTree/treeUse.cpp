#include<iostream>
#include"tree.h"
using namespace std;

TreeNode<int> * takeInput(){
    int data;
    cout << "Enter data" << endl;
    cin >> data;
    TreeNode<int>* root = new TreeNode<int>(data);
    int n;
    cout << "Enter Number of child" << endl;
    cin >> n;
    for (int i = 0; i < n; i++){
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

int main(){

}