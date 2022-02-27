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
    map<unsigned long long,vector<unsigned  long long>> foo;
    void solve(TreeNode *root,unsigned long long depth,unsigned long long place){
        if(root==nullptr)return;
        foo[depth].push_back(place);
        solve(root->left,depth+1,2*place+1);
        solve(root->right,depth+1,2*place+2);
        return;
    }
    int widthOfBinaryTree(TreeNode* root) {
        solve(root,0,0);
        long long res=0;
        for(auto x:foo){
            //cout << x.first << " : ";
            long long mini = x.second[0];
            long long maxi = x.second[0];
            for(long long y:x.second){
                //cout << y << " ";
                mini = min(mini,y);
                maxi = max(maxi,y);
            }
            //cout << endl;
            res = max(res,maxi-mini+1);
        }
        return res;
    }
};