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
    string result;
    string smallestFromLeaf(TreeNode* root) {
        for(int i=0;i<10000;i++){
            result+="z";
        }
        string cur="";
        generate(root,cur);
        return result;
    }
    void generate(TreeNode *root,string &cur){
        if(root== nullptr) return;
        if(root->left == nullptr and root->right == nullptr){
            cur.push_back(root->val+'a');
            reverse(cur.begin(),cur.end());
            result = min(result,cur);
            reverse(cur.begin(),cur.end());
            cur.pop_back();
            return;
        }
        cur.push_back(root->val+'a');
        generate(root->left,cur);
        generate(root->right,cur);
        cur.pop_back();
        return;
    }
};