/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr or head->next==nullptr) return nullptr;
        
        ListNode * slow = head;
        ListNode * fast = head->next;
        
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next;
            fast = fast->next;
            if(slow == fast) break;
        }
        if(fast==nullptr or fast->next==nullptr)return nullptr;
        
        fast = head;
        slow = slow->next;
        while(fast != slow){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};