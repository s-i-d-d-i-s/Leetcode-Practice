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
    
    
    void preOrder(TreeNode *root,queue<int> &queue){
        if(root == nullptr) return;
        preOrder(root->left,queue);
        queue.push(root->val);
        preOrder(root->right,queue);
        return;
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        queue<int> queue1;
        queue<int> queue2;
        preOrder(root1,queue1);
        preOrder(root2,queue2);
        vector<int> result;
        while(queue1.size()>0 and queue2.size()>0){
            if(queue1.front() < queue2.front()){
                result.push_back(queue1.front());
                queue1.pop();
            }else{
                result.push_back(queue2.front());
                queue2.pop();
            }
        }
        while(queue1.size() > 0){
            result.push_back(queue1.front());
            queue1.pop();
        }
        while(queue2.size() > 0){
            result.push_back(queue2.front());
            queue2.pop();
        }
        return result;
    }
};