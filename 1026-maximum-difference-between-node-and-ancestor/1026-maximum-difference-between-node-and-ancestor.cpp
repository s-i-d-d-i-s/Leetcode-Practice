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
    int result = INT_MIN;
    
    void dfs(TreeNode *root,int maximumParent,int minimumParent){
        if(root == nullptr) return ;
        if(minimumParent != INT_MAX){
            result = max(result, maximumParent - root->val);
            result = max(result,root->val - minimumParent);
        }
        dfs(root->left,max(maximumParent,root->val),min(minimumParent,root->val));
        dfs(root->right,max(maximumParent,root->val),min(minimumParent,root->val));
        return;
    }
    int maxAncestorDiff(TreeNode* root) {
        dfs(root,INT_MIN,INT_MAX);
        return result;
    }
};