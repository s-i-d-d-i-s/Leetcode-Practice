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
    int result=0;
    
    void dfs(TreeNode *root,int maxTillNow=INT_MIN){
        if(root == nullptr) return;
        
        if(root->val >= maxTillNow) result++;
        dfs(root->left,max(maxTillNow,root->val));
        dfs(root->right,max(maxTillNow,root->val));
    }
    int goodNodes(TreeNode* root) {
        dfs(root);
        return result;
    }
};