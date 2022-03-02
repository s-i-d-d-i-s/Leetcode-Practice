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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
        
        if(root->val > key){
            root->left = deleteNode(root->left,key);
        }else if(root->val < key){
            root->right = deleteNode(root->right,key);
        }else{
            /*
                1. Leaf
                2. 1-Child
                3. 2-Child
            */
            
            if(root->left == nullptr and root->right == nullptr){
                // Leaf 
                delete(root);
                return nullptr;
                
            }else if(root->left == nullptr or root->right == nullptr){
                // 1-Child
                TreeNode *node = root->left == nullptr? root->right : root->left; 
                delete(root);
                // Return the non-null node
                return node;
                
            }else{
                // 2-Child
                // Find the next node in inorder Traversal
                TreeNode * nextInOrder = root->right;
                while(nextInOrder->left != nullptr){
                    nextInOrder = nextInOrder->left;
                }
                root->val = nextInOrder->val;
                root->right = deleteNode(root->right,root->val);
                return root;
            }            
        }
        return root;
    }
};