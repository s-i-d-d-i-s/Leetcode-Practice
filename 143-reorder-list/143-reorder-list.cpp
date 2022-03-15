/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
    
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *beforeSlow = nullptr;
        
        while(fast && fast -> next){
            beforeSlow = slow;
            slow = slow -> next,
            fast = fast -> next -> next;
        }
        return beforeSlow;                    
    }
    void reorderList(ListNode* head) {
        if(head -> next == nullptr) return ;
        ListNode * mid = middleNode(head);
        ListNode * right = mid->next;
        mid->next=nullptr; 
        right = reverse(right);
        ListNode * last = new ListNode(-1);
        while(head!=nullptr and right!=nullptr){
            ListNode * nextHead = head->next;
            ListNode * nextRight = right->next;
            last->next = head;
            last = head;
            last->next = right;
            last = right;
            head = nextHead;
            right = nextRight;
        }
        return;
    }
    ListNode * reverse(ListNode *head){
        if(head == nullptr)return nullptr;
        if(head->next == nullptr) return head;
        
        ListNode *cursor = head;
        ListNode *last = nullptr;
        while(cursor!=nullptr){
            ListNode * next = cursor->next;
            cursor->next = last;
            last=cursor;
            cursor = next;
        }
        return last;
    }
};