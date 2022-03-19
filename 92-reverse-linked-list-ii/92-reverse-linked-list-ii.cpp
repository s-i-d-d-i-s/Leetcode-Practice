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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        
        // Head of list to be reversed
        ListNode * revHead = getKthNode(head,left);
        // Tail of list to be reversed
        ListNode * revTail = getKthNode(head,right);
        
        // Node previous to revhead
        ListNode * pre = getKthNode(head,left-1);           
        // Node after revTail
        ListNode * revTailNext = getKthNode(head,right+1);
                
        // Disconnect the revHead
        if(pre!=nullptr)        
            pre->next = nullptr;
                
        // Disconnect the revTail
        revTail->next=nullptr;
        
        revHead = reverse(revHead);
        revTail = getListLastNode(revHead);
        
        if(pre!=nullptr){
            pre->next = revHead;
            revTail->next = revTailNext;
            return head;
        }
        revTail->next = revTailNext;
        return revHead;
    }
    
    ListNode *reverse(ListNode *head){
        if(head==nullptr) return head;
        if(head->next == nullptr) return head;
        
        ListNode *child=head->next;
        ListNode * reversedList = reverse(head->next);
        child->next = head;
        head->next = nullptr;
        return reversedList;
    }
    
    ListNode * getKthNode(ListNode *head,int k){
        k--;
        if(k<0)return nullptr;
        
        while(k-->0 and head!=nullptr){
            head=head->next;
        }
        return head;
    }
    ListNode * getListLastNode(ListNode *head){        
        while(head->next != nullptr){
            head=head->next;
        }
        return head;
    }
};