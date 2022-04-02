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
    /*
        @ 0 -> leaf
        @ 1 -> parent of a leaf             // <- Takes the cam
        @ 2 -> parent of a parent of a leaf
        
    */
    int result=0;
    int minCameraCover(TreeNode* root) {
        int rootVal = getMinCam(root);
        if(rootVal == 0) result++;
        return result;
    }
    int getMinCam(TreeNode *root){
        
        if(root == nullptr) return 2;
        
        int left = getMinCam(root->left);
        int right = getMinCam(root->right);
        
        if(left == 0 or right == 0){
            result++;
            return 1;
        }
        if(left == 1 or right == 1 ){
            return 2;
        }

        return 0;
    }
};