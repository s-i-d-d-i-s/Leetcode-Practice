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
    set<int> deleteSet;
    vector<TreeNode*> result;
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto x:to_delete){
            deleteSet.insert(x);
        }
        root = deleteNodes(root);
        if(root != nullptr) result.push_back(root);
        return result;
    }
    TreeNode *deleteNodes(TreeNode *root){
        if(root == nullptr)
            return nullptr;
        
        root->left = deleteNodes(root->left);
        root->right = deleteNodes(root->right);
        
        if(deleteSet.find(root->val) != deleteSet.end()){
            // We need to delete this node
            
            if(root->left != nullptr and root->right != nullptr){
                // Both Subtrees Exists
                result.push_back(root->left);
                result.push_back(root->right);
            }else if(root->left != nullptr or root->right != nullptr){
                // At least one subtree exists
                if(root->left != nullptr){
                    result.push_back(root->left);                
                }else{
                    result.push_back(root->right);
                }
            }                        
            return nullptr;
        }
        return root;
    }
};