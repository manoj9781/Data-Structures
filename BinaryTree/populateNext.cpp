/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL){
            return root;
        }
       queue<Node *>pendingNodes;
        pendingNodes.push(root);
        while(pendingNodes.size() != 0){
            int size = pendingNodes.size();
            Node * newNode = NULL;
            for(int i = 0; i < size; i++){
                Node *front = pendingNodes.front();
                pendingNodes.pop();
                if(front -> right != NULL){
                    pendingNodes.push(front -> right);
                }
                if(front -> left != NULL){
                    pendingNodes.push(front -> left);
                }
                front -> next = newNode;
                newNode = front;
            }
        }
        return root;
    }
};