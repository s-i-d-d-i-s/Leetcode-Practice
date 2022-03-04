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
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> result;
        if(n == 1){
            result.push_back(new TreeNode(0));
            return result;
        }
        
        for(int left=1;left<=n-2;left++){
            int right = n-1 - left;
            auto leftSolution = allPossibleFBT(left);
            auto rightSolution = allPossibleFBT(right);
            for(auto leftSubtree : leftSolution){
                for(auto rightSubtree : rightSolution){
                    TreeNode *root = new TreeNode(0);
                    root->left = leftSubtree;
                    root->right = rightSubtree;
                    result.push_back(root);
                }
            }
        }
        
        return result;
    }
};