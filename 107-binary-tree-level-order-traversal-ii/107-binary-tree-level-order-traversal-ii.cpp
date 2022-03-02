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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr)return res;
        queue<TreeNode*> Q;
        Q.push(root);
        while(Q.size()>0){
            int cnt = Q.size();
            vector<int> curLvl;
            for(int i=0;i<cnt;i++){
                auto nod = Q.front();
                Q.pop();
                if(nod==nullptr)continue;
                curLvl.push_back(nod->val);
                Q.push(nod->left);
                Q.push(nod->right);
            }
            if(curLvl.size()!=0)
                res.push_back(curLvl);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};