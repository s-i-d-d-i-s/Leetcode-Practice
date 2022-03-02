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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==nullptr)
            return result;
        
        queue<TreeNode *> Q;
        Q.push(root);
        while(Q.size()>0){
            int cnt = Q.size();
            vector<int> level;
            for(int i=0;i<cnt;i++){
                auto node = Q.front();
                Q.pop();
                if(node == nullptr)continue;
                level.push_back(node->val);
                Q.push(node->left);
                Q.push(node->right);
            }
            if(level.size()>0)
                result.push_back(level);
        }
        return result;
    }
};