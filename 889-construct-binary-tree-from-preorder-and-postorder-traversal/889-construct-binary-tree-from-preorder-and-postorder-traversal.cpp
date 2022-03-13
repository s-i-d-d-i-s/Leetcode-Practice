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
    unordered_map<int,int> index;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i=0;i<postorder.size();i++){
            index[postorder[i]]=i;
        }
        int pt=0;
        return construct(0,postorder.size()-1,preorder,postorder,pt);
    }
    TreeNode* construct(int l,int r,vector<int>& preorder, vector<int>& postorder,int &pt) {
        if(l>r)return nullptr;        
        if(l==r){
            return new TreeNode(preorder[pt++]);
        }        
        TreeNode * node = new TreeNode(preorder[pt++]);
        int leftValue = preorder[pt];
        TreeNode * left = construct(l,index[leftValue],preorder,postorder,pt);
        TreeNode * right = construct(index[leftValue]+1,r-1,preorder,postorder,pt);
        node->left = left;
        node->right = right;
        return node;
    }
};