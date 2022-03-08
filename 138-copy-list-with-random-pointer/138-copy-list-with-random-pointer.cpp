/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

void traverse(Node *head){
    if(head==nullptr) return;
    cout << head->val << " -> ";
    traverse(head->next);
}
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr) return head;
        head=attachChild(head);
        Node *cursor = head;
        Node *dummyHead = head->next;
        while(cursor != nullptr){
            Node * originalChild = cursor->next->next;
            Node * originalRandom = cursor->random;
            Node * dummyChild = cursor->next;
            Node * dummyRandom = originalRandom!=nullptr?originalRandom->next:nullptr;            
            dummyChild->random = dummyRandom;            
            cursor = originalChild;
        }
        cursor = head;
        while(cursor != nullptr){
            Node * originalChild = cursor->next->next;            
            Node * dummyChild = cursor->next;            
            dummyChild->next = originalChild!=nullptr?originalChild->next:nullptr;            
            cursor->next = originalChild;
            cursor=originalChild;
        }
        return dummyHead;
    }
    
    Node * attachChild(Node *head){
        if(head==nullptr) return head;
        Node * originalChild = head->next;
        Node * dummyChild = new Node(head->val);
        head->next = dummyChild;
        dummyChild->next = originalChild;
        originalChild = attachChild(originalChild);
        return head;
    }
};