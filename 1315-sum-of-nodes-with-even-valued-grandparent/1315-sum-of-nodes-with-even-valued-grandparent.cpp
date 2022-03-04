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
    int sumEvenGrandparent(TreeNode* root,int parent = -1,int grandParent = -1) {
        if(root==nullptr)return 0;
        
        int result = 0;
        if(grandParent != -1 and grandParent%2==0){
            result += root->val;
        }
        result += sumEvenGrandparent(root->left,root->val,parent);
        result += sumEvenGrandparent(root->right,root->val,parent);
        return result;
    }
};