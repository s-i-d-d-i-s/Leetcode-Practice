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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode *getMid(ListNode *head){
        if(head->next == nullptr)return head;
        if(head == nullptr)return head;
        
        ListNode *fast=head;
        ListNode *slow=head;
        ListNode *beforeSlow=nullptr;
        
        while(fast!=nullptr){
            fast=fast->next;
            if(fast==nullptr)break;
            fast=fast->next;
            beforeSlow=slow;
            slow=slow->next;
        }
        
        beforeSlow->next = nullptr;
        
        return slow;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr)return nullptr;
        if(head->next == nullptr) return new TreeNode(head->val);
        ListNode *mid = getMid(head);
        TreeNode *root = new TreeNode(mid->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        return root;
    }
};