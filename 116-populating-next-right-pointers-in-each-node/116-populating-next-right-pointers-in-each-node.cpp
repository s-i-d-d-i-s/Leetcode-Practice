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

        *
       /  \
  0-> * -> *
     / \  / \
    *   **   *

*/
     
class Solution {
public:
    Node* connect(Node* root) {
        Node * cur = root;
        while(cur!=nullptr){
            Node *dummy = new Node(-1);
            Node *prev = dummy;
            while(cur != nullptr){
                if(cur->left != nullptr){
                    prev->next = cur->left;
                    prev = prev->next;
                }
                if(cur->right != nullptr){
                    prev->next = cur->right;
                    prev = prev->next;
                }
                cur = cur->next;
            }
            cur = dummy->next;
        }
        return root;
    }
};