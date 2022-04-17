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
    // result = inorder(root.left) + root +   inorder(root.right)
    //             section 1       section 2     section 3
    TreeNode* increasingBST(TreeNode* root, TreeNode *next_section_head=nullptr) {
        if(!root)return next_section_head;
        // if current node is null return the head to next section
        auto left_section_head = increasingBST(root->left,root);
        root->left=nullptr;
        root->right = increasingBST(root->right,next_section_head);
        return left_section_head;
    }
};