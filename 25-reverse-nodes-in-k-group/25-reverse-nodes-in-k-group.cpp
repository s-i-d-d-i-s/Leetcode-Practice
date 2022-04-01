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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        
        int currentLength = getLength(head);
        if(currentLength < k){
            return head;
        }
        
        // We actually have K nodes
        ListNode * connectionPoint = getKthNode(head,k-1);
        
        ListNode * subproblem = connectionPoint->next;
        
        // Disconnect
        connectionPoint->next = nullptr;
        
        
        // Reverse the segment
        ListNode * reversedHead = reverseList(head);
        
        ListNode * reversedTail = getTail(reversedHead);
        
        subproblem = reverseKGroup(subproblem,k);
        
        // Connect
        reversedTail->next = subproblem;
        
        return reversedHead;
    }
    
    int getLength(ListNode * head){
        int result=0;
        while(head != nullptr){
            result++;
            head = head->next;
        }
        return result;
    }
    
    ListNode * getKthNode(ListNode * head,int k){
        ListNode * result=head;
        while(k>0){
            result = result->next;
            k--;
        }
        return result;
    }
    
    ListNode * getTail(ListNode * head){
        ListNode * result=head;
        while(result->next != nullptr){
            result = result->next;
        }
        return result;
    }
    
    // 1 ->[ 3 -> 4 -> 5 -> 2]
    ListNode * reverseList(ListNode * head){
        if(head==nullptr or head->next == nullptr) return head;
        ListNode * child = head->next;
        ListNode * result = reverseList(head->next);
        child->next = head;
        head->next = nullptr;
        return result;
    }
};