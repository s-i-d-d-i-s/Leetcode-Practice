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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr or head->next == nullptr)return head;
        ListNode* one = head;
        ListNode* two = head->next;
        ListNode* three = head->next->next;
        two->next = one;
        one->next = swapPairs(three);
        return two;
    }
};