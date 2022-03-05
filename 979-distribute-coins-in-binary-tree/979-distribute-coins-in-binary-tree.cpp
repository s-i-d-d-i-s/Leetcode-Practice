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
    int balanceTree(TreeNode * root){
        if(root == nullptr) return 0;
        int haveCoins = root->val;
        int left = balanceTree(root->left);
        int right  = balanceTree(root->right);
        result += (abs(left)+abs(right));
        int currentBalance = -1 + haveCoins + left + right;
        return currentBalance;
    }
    int distributeCoins(TreeNode* root) {
        balanceTree(root);
        return result;
    }
};