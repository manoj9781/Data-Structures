#include<iostream>
#include<climits>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
    };



class BST{
    public:
    int maximum;
    int minimum;
    int size;
    bool isBST;
};


BST LargestBST(TreeNode<int> *root, int &ans){
    if(root == NULL){
        return {
            INT_MIN, INT_MAX, 0, true
        };
    }
    BST left = LargestBST(root -> left, ans);
    BST right = LargestBST(root -> right, ans);
    
    BST temp;
    temp.size = left.size + right.size + 1;
    temp.maximum = max(root -> data, right.maximum);
    temp.minimum = min(root -> data, left.minimum);
    
    if(left.isBST && right.isBST &&(root -> data > left.maximum && root -> data < right.minimum)){
        temp.isBST = true;
    }
    else{
        temp.isBST = false;
    }
    if(temp.isBST){
        ans = max(ans, temp.size);
    }
    return temp;
}


int largestBST(TreeNode<int>* root) 
{
    int maxSize = 0;
    BST ans = LargestBST(root, maxSize);
    return maxSize;    
}
