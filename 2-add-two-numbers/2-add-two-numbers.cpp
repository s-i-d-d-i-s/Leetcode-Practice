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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2,int carry=0) {
        if(l1 == nullptr and l2==nullptr and carry==0) return nullptr;
        int top = l1!=nullptr?l1->val:0;
        int bottom = l2!=nullptr?l2->val:0;
        
        int netValue = top+bottom+carry;
        if(netValue>=10){
            carry = 1;
            netValue=netValue%10;
        }else{
            carry=0;
        }
        ListNode * head = new ListNode(netValue);
        head->next = addTwoNumbers(l1!=nullptr?l1->next:l1,
                                   l2!=nullptr?l2->next:l2,
                                  carry);
        return head;
    }
};