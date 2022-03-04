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
    map<int,vector<pair<TreeNode *,int>>> nodes;    
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode *,pair<int,int>>> Q;
        Q.push({root,{0,0}});
        
        while(Q.size()>0){
            int count = Q.size();            
            for(int i=0;i<count;i++){
                auto  node = Q.front();
                Q.pop();    
                int row = node.second.second;
                int col = node.second.first;
                nodes[col].push_back({node.first,row});
                
                if(node.first->left){
                    Q.push({node.first->left,{col-1,row+1}});
                }
                if(node.first->right){
                    Q.push({node.first->right,{col+1,row+1}});
                }
            }            
        }
        vector<vector<int>> result;
        for(auto x:nodes){
            sort(nodes[x.first].begin(),nodes[x.first].end(),[](pair<TreeNode *,int> &a,
                                                                pair<TreeNode *,int> &b){
                if(a.second == b.second){
                    return a.first->val < b.first->val;
                }
                return a.second<b.second;
            });
            vector<int> current;
            for(auto y:nodes[x.first]){
                current.push_back(y.first->val);
            }
            result.push_back(current);
        }
        return result;
    }
};