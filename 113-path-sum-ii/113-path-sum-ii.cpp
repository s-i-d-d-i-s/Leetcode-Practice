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

    vector<vector<int>> res;
    vector<int> cur;
    void solve(TreeNode *root,int targetSum,int curSum=0){
        if(root==nullptr)return ;
        
        curSum += root->val;
        cur.push_back(root->val);
        
        if(root->left == nullptr and root->right==nullptr){
            if(curSum == targetSum){
                res.push_back(cur);
            }
        }else{
            solve(root->left,targetSum,curSum);
            solve(root->right,targetSum,curSum);
        }
        curSum -= root->val;
        cur.pop_back();
        return ;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        solve(root,targetSum);
        return res;
    }
};