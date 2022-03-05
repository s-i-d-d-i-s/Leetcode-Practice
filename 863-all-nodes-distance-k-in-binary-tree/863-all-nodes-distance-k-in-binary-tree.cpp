/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> result;
    unordered_map<TreeNode *,TreeNode *> getParent;
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        getParentForAllNodes(root);
        
        
        queue<pair<TreeNode *,int>> Q;
        unordered_map<int,int> visited;
        
        Q.push({target,0});
        visited[target->val]=true;
        while(Q.size()>0){
            auto node = Q.front();
            Q.pop();
            if(node.second > k)
                continue;
            if(node.second==k){
                result.push_back(node.first->val);
                continue;
            }
            if(node.first->left!=nullptr and !visited[node.first->left->val]){
                visited[node.first->left->val]=true;
                Q.push({node.first->left,node.second+1});                
            }
            if(node.first->right!=nullptr and !visited[node.first->right->val]){
                visited[node.first->right->val]=true;
                Q.push({node.first->right,node.second+1});
            }
            if(getParent[node.first]!=nullptr and !visited[getParent[node.first]->val]){
                visited[getParent[node.first]->val]=true;
                Q.push({getParent[node.first],node.second+1});
            }
        }
        
        return result;
    }
    
    void getParentForAllNodes(TreeNode *root,TreeNode *parent=nullptr){
        if(root==nullptr) return;
        getParentForAllNodes(root->left,root);
        if(parent != nullptr){
            getParent[root]=parent;
        }
        getParentForAllNodes(root->right,root);
    }
};