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
    TreeNode *deepestLeftNode;
    TreeNode *deepestRightNode;
    
    void inOrder(TreeNode *root,bool goLeft=true,int depth=0){
        if(root==nullptr) return;
        
        if(goLeft and depth>maxDepth){
            deepestLeftNode = root;
            maxDepth=depth;
        }else if(!goLeft and depth>maxDepth){
            deepestRightNode = root;
            maxDepth=depth;
        }
        
        if(goLeft){
            inOrder(root->left,goLeft,depth+1);
            inOrder(root->right,goLeft,depth+1);
        }else{
            inOrder(root->right,goLeft,depth+1);
            inOrder(root->left,goLeft,depth+1);
        }
        return;
    }
    
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        inOrder(root,true);
        maxDepth=-1;
        inOrder(root,false);
        return findLCA(root);
    }
    
    TreeNode * findLCA(TreeNode *root){
        if(root == nullptr) return nullptr;
        
        if(root->val == deepestLeftNode->val or root->val == deepestRightNode->val )
            return root;
        
        auto left = findLCA(root->left);
        auto right = findLCA(root->right);
        
        if(left == nullptr and right == nullptr) return nullptr;
        if(left == nullptr) return right;
        if(right == nullptr) return left;
        return root;
    }
};