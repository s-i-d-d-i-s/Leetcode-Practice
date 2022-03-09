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
    ListNode* deleteDuplicates(ListNode* head,int skip=INT_MIN) {
        if(head == nullptr) return head;
        if(head->val == skip)
            return deleteDuplicates(head->next,skip);
        
        if(head->next and head->next->val == head->val)
            return deleteDuplicates(head->next,head->val);
        
        head->next = deleteDuplicates(head->next);
        return head;
    }
};