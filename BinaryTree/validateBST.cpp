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

bool isValid(TreeNode *root, int min = INT_MIN, int max = INT_MAX){
    if(root == NULL){
        return true;
    }
    if(root -> val < min || root -> val >  max){
        return false;
    }
    bool leftAns = isValid(root->left, min, root->val - 1);
    bool rightAns = isValid(root->right, root->val, max);
    return leftAns && rightAns;
}

int main(){
    cout << "validate" << endl;
}