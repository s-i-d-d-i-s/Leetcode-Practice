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
    int maxDepth = -1;
    set<int> deepestLeafNodes;
    
    void inOrder(TreeNode *root,int depth=0){
        if(root==nullptr) return;
        if(depth>maxDepth){
            deepestLeafNodes.clear();
            deepestLeafNodes.insert(root->val);
            maxDepth = depth;
        }else if(depth == maxDepth){
            deepestLeafNodes.insert(root->val);
        }
        
        inOrder(root->left,depth+1);
        inOrder(root->right,depth+1);
        return;
    }
    
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        inOrder(root);
        return findLCA(root);
    }
    
    TreeNode * findLCA(TreeNode *root){
        if(root == nullptr) return nullptr;
        
        if(deepestLeafNodes.find(root->val) != deepestLeafNodes.end())
            return root;
        
        auto left = findLCA(root->left);
        auto right = findLCA(root->right);
        
        if(left == nullptr and right == nullptr) return nullptr;
        if(left == nullptr) return right;
        if(right == nullptr) return left;
        return root;
    }
};