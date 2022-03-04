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
    unordered_map<int,int> getIndex;
    
    
    TreeNode * build(vector<int>& preorder, vector<int>& inorder,int l,int r,int &preIndex){
        if(l>r)return nullptr;
        TreeNode *root = new TreeNode(preorder[preIndex]);
        int indexInorder = getIndex[preorder[preIndex]];
        preIndex++;
        
        root->left = build(preorder,inorder,l,indexInorder-1,preIndex);
        root->right = build(preorder,inorder,indexInorder+1,r,preIndex);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)
            getIndex[inorder[i]]=i;        
        int preIndex=0;
        return build(preorder,inorder,0,inorder.size()-1,preIndex);        
    }
};