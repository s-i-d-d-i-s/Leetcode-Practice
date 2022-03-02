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
    
    
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> result;
        if(root == nullptr) return result;
        queue<TreeNode *> Q;
        Q.push(root);
        
        while(Q.size()>0){
            int cnt=Q.size();
            for(int i=0;i<cnt;i++){
                auto node = Q.front();
                Q.pop();
                if(i==0) result.push_back(node->val);
                if(node->right != nullptr) Q.push(node->right);
                if(node->left != nullptr) Q.push(node->left);
            }
        }
        return result;
    }
};