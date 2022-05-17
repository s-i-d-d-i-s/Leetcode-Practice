/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original == nullptr) return original;
        
        if(target->val == original->val)return cloned;
        
        auto right= getTargetCopy(original->right,cloned->right,target);
        auto left = getTargetCopy(original->left,cloned->left,target);
        if(left != nullptr) return left;
        return right;
    }
};