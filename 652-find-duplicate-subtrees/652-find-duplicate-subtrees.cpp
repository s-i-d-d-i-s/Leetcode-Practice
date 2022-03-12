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
    map<string,vector<TreeNode*>> dp;
    string depthFirstSearch(TreeNode* root){
        if(root == nullptr){
            return "";
        }
        string left = depthFirstSearch(root->left);
        string right = depthFirstSearch(root->right);
        string serialCurrent =  to_string(root->val) + "(" + left + ")" + "(" + right + ")";
        dp[serialCurrent].push_back(root);
        return serialCurrent;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> result;
        depthFirstSearch(root);
        for(auto x:dp){
            if(x.second.size()>1){
                result.push_back(x.second[0]);
            }
        }
        return result;
    }
};