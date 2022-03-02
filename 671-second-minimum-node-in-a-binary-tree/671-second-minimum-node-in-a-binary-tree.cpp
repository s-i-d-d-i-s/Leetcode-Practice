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
    long minimum=LONG_MAX;
    long secondMinimum=LONG_MAX;
    
    void inorder(TreeNode *root){
        if(root==nullptr)return;
        
        //      val [m sm] -> [val,m]
        if(root->val < minimum){
            swap(minimum,secondMinimum);
            minimum = root->val;
        }
        
        //      [m sm] val -> [m,sm]
        // Do Nothing
        
        //      [m  val sm]  -> [m,sm]
        else if(root->val > minimum and root->val < secondMinimum){
            secondMinimum = root->val;
        }
        
        
        inorder(root->left);
        inorder(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        inorder(root);
        if(secondMinimum == LONG_MAX) return -1;
        return secondMinimum;
    }
};