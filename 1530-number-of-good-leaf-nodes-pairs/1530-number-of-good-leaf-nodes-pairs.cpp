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
    int solution=0;
    int countPairs(TreeNode* root, int distance) {
        if(root == nullptr) return 0;
        getLeafDistance(root,distance);
        return solution;
    }
    unordered_map<int,int> getLeafDistance(TreeNode *root,int distance){
        unordered_map<int,int> result;
        if(root==nullptr) return result;
        
        if(root->left == nullptr and root->right==nullptr){
            result[1]++;
            return result;
        }
        
        auto leftLeafs = getLeafDistance(root->left,distance);
        auto rightLeafs = getLeafDistance(root->right,distance);
        
        for(auto x:leftLeafs)
            for(auto y:rightLeafs)
                if((x.first+y.first)<=distance)
                    solution+=(x.second * y.second);                                    
        
        for(auto x:leftLeafs)
            result[x.first+1]+=x.second;        
        for(auto x:rightLeafs)
            result[x.first+1]+=x.second;
        
        return result;
    }
};