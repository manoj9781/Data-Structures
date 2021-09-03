#include<iostream>
#include<vector>
using namespace std;

void inorder(TreeNode *root, vector<int> &v){
    if(root == NULL){
        return;
    }
    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right);
}

bool isValidate(TreeNode *root){
    if(root == NULL){
        return root;
    }
    vector<int> v;
    inorder(root, v);
    for (int i = 1; i < v.size();i++){
        if(v[i-1] >= v[i]){
            return false;
        }
    }
    return true;
}

int main(){
    cout << "validate" << endl;
}