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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr or head->next == nullptr) return head;
        if(head->val == head->next->val){
            if(head->next->next == nullptr or head->next->next->val != head->val)
                return deleteDuplicates(head->next->next);
            else
                return deleteDuplicates(head->next);
        }
        head->next = deleteDuplicates(head->next);
        return head;
    }
};