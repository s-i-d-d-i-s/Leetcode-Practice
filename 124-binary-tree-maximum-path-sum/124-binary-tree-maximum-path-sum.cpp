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
    int res=INT_MIN;
    int getMaxPathSumFromRoot(TreeNode *root){
        if(root == nullptr)
            return 0;
        
        
        int left = getMaxPathSumFromRoot(root->left);
        int right = getMaxPathSumFromRoot(root->right);
        
        res = max(res,right+root->val+left);
        int solution = max(root->val,root->val + max(left,right));
        res = max(res,solution);
        
        return solution;
    }
    int maxPathSum(TreeNode* root) {
        getMaxPathSumFromRoot(root);
        return res;
    }
};