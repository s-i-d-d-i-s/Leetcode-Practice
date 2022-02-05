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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](ListNode *a,ListNode *b){
            if(a==nullptr) return true;
            if(b==nullptr) return false;    
            return a->val < b->val;
        };
        multiset<ListNode*,decltype(comp)> ss(comp);
        for(auto x:lists){
            ss.insert(x);
        }
        ListNode *root=nullptr;
        ListNode *current=nullptr;
        while(ss.size()>0){
            auto cur = *ss.begin();
            ss.erase(ss.begin());
            if(cur==nullptr)continue;
            if(root == nullptr){
                current=cur;
                root=current;
                ss.insert(cur->next);            
            }else{
                current->next=cur;
                current=current->next;
                ss.insert(cur->next);            
            }
        }
        return root;
    }
};