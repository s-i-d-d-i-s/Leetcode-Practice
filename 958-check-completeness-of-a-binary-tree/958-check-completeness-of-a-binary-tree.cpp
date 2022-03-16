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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);
        bool metNull=false;
        while(Q.size()>0){
            auto node = Q.front();
            Q.pop();
            if(node == nullptr){
                metNull=true;
            }else{
                if(metNull) return false;
                Q.push(node->left);
                Q.push(node->right);
            }
        }
        return true;
    }
};