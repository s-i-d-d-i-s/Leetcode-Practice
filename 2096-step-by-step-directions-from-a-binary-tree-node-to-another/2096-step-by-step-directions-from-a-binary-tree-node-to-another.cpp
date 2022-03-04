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
    
    TreeNode * lowestCommonAncestor(TreeNode *root,int value1,int value2){
        if(root == nullptr) return nullptr;
        
        if(root->val == value1){
            return root;
        }
        
        if(root->val == value2){
            return root;
        }
        
        auto left = lowestCommonAncestor(root->left,value1,value2);
        auto right = lowestCommonAncestor(root->right,value1,value2);
        
        if(left != nullptr and right!=nullptr){
            return root;
        }
        if(left == nullptr) return right;
        return left;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode * LCSNode = lowestCommonAncestor(root,startValue,destValue);
        
        string result="";
        getPathFromSource(LCSNode,startValue,result);
        getPathToDestination(LCSNode,destValue,result);        
        
        return result;
    }
    
    bool getPathFromSource(TreeNode *root,int value,string &result){
        if(root == nullptr)return false;
        if(root->val == value) return true;        
        result.push_back('U');
        if(getPathFromSource(root->left,value,result)) return true;
        if(getPathFromSource(root->right,value,result)) return true;
        result.pop_back();
        return false;
    }
    
    bool getPathToDestination(TreeNode *root,int value,string &result){
        if(root == nullptr)return false;
        if(root->val == value) return true;        
        result.push_back('L');
        if(getPathToDestination(root->left,value,result)) return true;
        result.pop_back();
        result.push_back('R');
        if(getPathToDestination(root->right,value,result)) return true;
        result.pop_back();
        return false;
    }
    
};