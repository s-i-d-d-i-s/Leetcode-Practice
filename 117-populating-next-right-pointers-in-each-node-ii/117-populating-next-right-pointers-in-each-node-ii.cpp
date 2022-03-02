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
        if(root == nullptr) return nullptr;
        
        Node *current = root;
        while(current!=nullptr){
            Node * lastUsedNode = new Node(-1);
            Node * originalLastUsedNode = lastUsedNode;
            Node * parent = current;
            while(parent != nullptr){
                if(parent -> left != nullptr){
                    lastUsedNode ->next = parent->left;
                    lastUsedNode = lastUsedNode->next;
                }
                if(parent -> right != nullptr){
                    lastUsedNode ->next = parent->right;
                    lastUsedNode = lastUsedNode->next;
                }
                parent = parent->next;
            }
            current = originalLastUsedNode->next;
        }
        return root;
    }
};