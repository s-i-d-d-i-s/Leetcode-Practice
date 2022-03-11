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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        int n = getLengthOfLinkedList(head);
        k%=n;
        if(k == 0)return head;
        k = n - k;
        ListNode * end = getKthNode(head,k+1);
        ListNode * newEnd = getKthNode(head,k);
        makeCircular(head,head);
        newEnd->next = nullptr;
        return end;
    }
    int getLengthOfLinkedList(ListNode *head){
        int result=0;
        while(head != nullptr){
            result++;
            head = head->next;
        }
        return result;
    }
    ListNode * getKthNode(ListNode * head,int k){
        k--;
        while(head->next != nullptr and k-->0){
            head= head->next;
        }
        return head;
    }
    void makeCircular(ListNode *cursor,ListNode *head){
        while(cursor->next != nullptr){
            cursor= cursor->next;
        }
        cursor->next = head;
        return;
    
    }
};