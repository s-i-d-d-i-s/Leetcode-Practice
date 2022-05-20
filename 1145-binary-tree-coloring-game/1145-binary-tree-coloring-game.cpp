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
    int totalNodes;
    bool result = false;
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        totalNodes = n;
        findSolution(root,x);
        return result;
    }
    
    void findSolution(TreeNode *root,int x){
        if(root == nullptr) return;
        if(root->val == x){
            int left = countNodes(root->left);
            int right = countNodes(root->right);
            int parent = totalNodes - left - right - 1;
            if(parent > (left + right)){
                result = true;
            }else if(left > (parent + right)){
                result = true;
            }else if(right > (left + parent)){
                result = true;
            }
        }
        findSolution(root->left,x);
        findSolution(root->right,x);
    }
    
    int countNodes(TreeNode *root){
        if(root == nullptr) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
};