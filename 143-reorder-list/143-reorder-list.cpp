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
    void reorderList(ListNode* head) {
        vector<ListNode*> stk;
        ListNode* cursor = head;
        while(cursor != nullptr){
            stk.push_back(cursor);
            cursor=cursor->next;
        }
        cursor = head;
        int n = stk.size()/2;
        
        while(n--){
            ListNode * last=stk.back();
            ListNode * next=cursor->next;
            stk.pop_back();
            cursor->next = last;
            last->next = next;
            cursor = next;
        }
        cursor->next = nullptr;
        return;
    }
};