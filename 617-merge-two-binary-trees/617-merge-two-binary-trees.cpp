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
    TreeNode* merge(TreeNode* root1, TreeNode* root2){
        if(root1 == nullptr and root2 == nullptr) return nullptr;
        if(root1 == nullptr or root2 == nullptr)
            return root1 == nullptr ? root2 : root1;
        
        TreeNode *cur = new TreeNode (root1->val + root2->val);
        cur->left = merge(root1->left,root2->left);
        cur->right = merge(root1->right,root2->right);
        return cur;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return merge(root1,root2);
    }
};