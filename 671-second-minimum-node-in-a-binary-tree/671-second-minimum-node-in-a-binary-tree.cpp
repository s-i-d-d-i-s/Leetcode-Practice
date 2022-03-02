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
    long firstElement=LONG_MAX;
    long secondElement=LONG_MAX;
    
    void inorder(TreeNode *root){
        if(root==nullptr)return;
        
        if(firstElement > root->val){
            swap(firstElement,secondElement);
            firstElement = root->val;
        }else if(firstElement < root->val and secondElement > root->val){
            secondElement = root->val;
        }
        
        inorder(root->left);
        inorder(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        inorder(root);
        if(secondElement == LONG_MAX) return -1;
        return secondElement;
    }
};