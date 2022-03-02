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
    TreeNode *faulty=nullptr;
    
    bool findFaulty(TreeNode *root){
        if(root==nullptr)return false;
        
        if(findFaulty(root->right))return true;
        
        if(faulty == nullptr){
            faulty= root;
        }else{
            if(root->val > faulty->val){
                return true;
            }else{
                faulty= root;
            }
        }
        if(findFaulty(root->left))return true;
        return false;
    }
    
    bool inorder(TreeNode *root){
        if(root==nullptr)return false;
        if(inorder(root->left))return true;
        if(root->val>faulty->val){
            swap(root->val,faulty->val);
            return true;
        }
        if(inorder(root->right))return true;
        return false;
    }
    void recoverTree(TreeNode* root) {
        findFaulty(root);
        cout << faulty->val << endl;
        inorder(root);
    }
};