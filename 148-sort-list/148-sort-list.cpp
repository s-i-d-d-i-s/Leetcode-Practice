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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr or head->next==nullptr)return head;
        ListNode *fast=head;
        ListNode *slow=head;
        ListNode *beforeSlow= nullptr;
        while(fast!=nullptr){
            fast=fast->next;
            if(fast!=nullptr)fast = fast->next;
            beforeSlow=slow;
            slow=slow->next;
        }
        beforeSlow->next=nullptr;
        head = sortList(head);
        slow = sortList(slow);
        ListNode *result=merge(head,slow);
        return result;
    }
    ListNode * merge(ListNode *n1,ListNode *n2){
        ListNode *dummy=new ListNode(-1);
        ListNode *result=dummy;
        while(n1!=nullptr and n2!=nullptr){
            if(n1->val < n2->val){
                dummy->next = n1;
                n1=n1->next;
                dummy=dummy->next;
                dummy->next = nullptr;                                
            }else{
                dummy->next = n2;
                n2=n2->next;
                dummy=dummy->next;
                dummy->next = nullptr;
            }
        }
        while(n1!=nullptr){
            dummy->next = n1;
            n1=n1->next;
            dummy=dummy->next;
            dummy->next = nullptr;
        }
        while(n2!=nullptr){
            dummy->next = n2;
            n2=n2->next;
            dummy=dummy->next;
            dummy->next = nullptr;
        }
        return result->next;
    }
};