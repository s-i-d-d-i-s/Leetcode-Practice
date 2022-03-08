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

class DSU{
    public:
    vector<int> parent;
    DSU(int n){
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    
    int root(int n){
        if(n == parent[n])return n;
        parent[n] = root(parent[n]);
        return parent[n];
    }
    void uni(int a,int b){
        int r1 = root(a);
        int r2 = root(b);
        if(r1 == r2)return;
        parent[r2]=r1;
    }
    bool find(int a,int b){
        int r1 = root(a);
        int r2 = root(b);
        return r1==r2;
    }
    
};

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        DSU dsu(1e5);
        set<int> s;
        for(int x:nums){
            s.insert(x);
        }
        while(head and head->next){
            if(s.find(head->val) != s.end() and s.find(head->next->val) != s.end())
                dsu.uni(head->val,head->next->val);
            head=head->next;
        }
        s.clear();
        for(int x:nums){
            s.insert(dsu.root(x));
        }
        return s.size();
    }
};