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
    int maxLevelSum(TreeNode* root) {
        int level=0;
        int maxSum=INT_MIN;
        queue<TreeNode *> Q;
        Q.push(root);
        int levelNo=1;
        while(Q.size()>0){
            int count = Q.size();
            int sum = 0;
            for(int i=0;i<count;i++){
                auto node = Q.front();
                Q.pop();
                sum += node->val;
                if(node->left != nullptr)
                    Q.push(node->left);
                if(node->right != nullptr)
                    Q.push(node->right);
            }
            if(sum > maxSum){
                maxSum=sum;
                level=levelNo;
            }
            levelNo++;
        }
        return level;
    }
};