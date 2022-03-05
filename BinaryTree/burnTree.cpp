/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

#include<bits/stdc++.h>
#include "BinaryTreeUse.cpp"
BinaryTreeNode<int> *parentMapping(BinaryTreeNode<int> *root, int start, unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int> *>&map){
    queue<BinaryTreeNode<int>*> pendingNodes;
    BinaryTreeNode<int> *ans = NULL;
    pendingNodes.push(root);
    map[root] = NULL;
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if(front -> data == start){
            ans = front;
        }
        if(front -> left != NULL){
            pendingNodes.push(front -> left);
            map[front -> left]  = front;
        }
        if(front -> right != NULL){
            pendingNodes.push(front -> right);
            map[front -> right] = front;
        }
    }
    return ans;
}

int burnTree(BinaryTreeNode<int> *root,unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int> *>map){
    unordered_map<BinaryTreeNode<int> *, bool> visited;
    queue<BinaryTreeNode<int> *>pendingNodes;
    pendingNodes.push(root);
    visited[root] = true;
    int ans = 0;
    while(pendingNodes.size() != 0){
        int size = pendingNodes.size();
        int flag = false;
        for(int i = 0; i < size; i++){
            BinaryTreeNode<int> *front = pendingNodes.front();
            pendingNodes.pop();
            if(front -> left != NULL && !visited[front -> left]){
                flag = true;
                pendingNodes.push(front -> left);
                visited[front -> left] = true;
            }
            if(front -> right != NULL && !visited[front -> right]){
                flag = true;
                pendingNodes.push(front -> right);
                visited[front -> right] = true;
            }
            if(map[front] && !visited[map[front]]){
                flag = true;
                pendingNodes.push(map[front]);
                visited[map[front]] = true;
            }
        }
        if(flag == true){
            ans += 1;
        }
    }
    return ans;
}


int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
   unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int> *>map;
    BinaryTreeNode<int> *ans = parentMapping(root, start, map);
    int result = burnTree(ans, map);
    return result;
}
