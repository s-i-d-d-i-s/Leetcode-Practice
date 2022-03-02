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
    bool isValidBST(TreeNode* root,long l=INT_MIN,long r=INT_MAX) {
        if(root==nullptr){
            return true;
        }
        if(root->val >= l and root->val<=r){
            return isValidBST(root->left,l,(long)(root->val)-1) && isValidBST(root->right,(long)(root->val)+1,r);
        }
        return false;
        
    }
};