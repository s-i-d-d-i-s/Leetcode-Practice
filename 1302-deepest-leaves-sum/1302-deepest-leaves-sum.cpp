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
    int sum=0;
    int maxDepth=-1;
    
    void calculateDeepestLeafSum(TreeNode *root,int depth=0){
        if(root==nullptr)return;
        if(depth > maxDepth){
            sum=root->val;
            maxDepth = depth;
        }else if(depth == maxDepth){
            sum += (root->val);
        }
        calculateDeepestLeafSum(root->left,depth+1);
        calculateDeepestLeafSum(root->right,depth+1);
        return;
    }
    int deepestLeavesSum(TreeNode* root,int depth=0) {
        calculateDeepestLeafSum(root);
        return sum;
    }
};