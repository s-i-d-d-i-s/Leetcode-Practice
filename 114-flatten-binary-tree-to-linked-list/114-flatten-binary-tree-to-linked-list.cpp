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
    TreeNode *flattenTree(TreeNode *root,TreeNode *addAtBottom=nullptr){
        if(root == nullptr) return addAtBottom;
        root->right = flattenTree(root->right,addAtBottom);
        root->right = flattenTree(root->left,root->right);
        root->left = nullptr;
        return root;
    }
    void flatten(TreeNode* root) {
        flattenTree(root);
        return;
    }
};