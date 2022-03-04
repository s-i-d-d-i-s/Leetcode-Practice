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
    int solution=1;
    int longestUnivaluePathFromRoot(TreeNode *root){
        if(root == nullptr) return 0;
        int left = longestUnivaluePathFromRoot(root->left);
        int right = longestUnivaluePathFromRoot(root->right);
        int result=1;
        if(root->left!=nullptr  and  root->left->val != root->val){
            left=0;
        }
        if(root->right!=nullptr  and  root->right->val != root->val){
            right=0;
        }
        solution = max(solution,result+left+right);
        return result+max(left,right);
    }
    int longestUnivaluePath(TreeNode* root) {
        longestUnivaluePathFromRoot(root);
        return solution-1;
    }
};