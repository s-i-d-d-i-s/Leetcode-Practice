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
    int distributeCoins(TreeNode* root) {
        getStatus(root);
        return result;
    }
    
    int getStatus(TreeNode *root){
        if(root == nullptr) return 0;
        int left = getStatus(root->left);
        int right = getStatus(root->right);
        int movement = abs(left) + abs(right);
        result += movement;
        return left+right-1+root->val;
    }
};