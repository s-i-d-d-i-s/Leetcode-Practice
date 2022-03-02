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
    
    TreeNode *flattenTree(TreeNode *root,TreeNode *nextSection=nullptr){
        if(root == nullptr) return nextSection;
        
        root->right = flattenTree(root->right,nextSection);
        auto left = flattenTree(root->left,root->right);
        root->left = nullptr;
        root->right = left;
        return root;
    }
    void flatten(TreeNode* root) {
        flattenTree(root);
        return;
    }
};