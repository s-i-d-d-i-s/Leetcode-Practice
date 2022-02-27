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
typedef unsigned long long ll;
class Solution {
public:
    vector<ll> left;
    int solve(TreeNode *root,ll depth,ll place){
        if(root==nullptr)return 0;
        if(depth>=left.size()){
            left.push_back(place);
        }
        int cur = place-left[depth]+1;
        return max({cur,solve(root->left,depth+1,2*place),solve(root->right,depth+1,2*place+1)});
    }
    int widthOfBinaryTree(TreeNode* root) {        
        return solve(root,0,1);;
    }
};