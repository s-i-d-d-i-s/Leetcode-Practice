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
    vector<TreeNode *> nodes;
    
    void inorder(TreeNode *root){
        if(root == nullptr) return ;
        inorder(root->left);
        nodes.push_back(root);
        inorder(root->right);
        return;
    }
    TreeNode *build(int l,int r){
        if(l>r)return nullptr;
        if(l==r){
            nodes[l]->left= nullptr;
            nodes[l]->right= nullptr;
            return nodes[l];
        }
        int m = (l+r)/2;
        nodes[m]->left = build(l,m-1);
        nodes[m]->right = build(m+1,r);
        return nodes[m];
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return build(0,nodes.size()-1);
    }
};