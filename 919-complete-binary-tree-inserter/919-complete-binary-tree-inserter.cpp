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
class CBTInserter {
public:
    TreeNode* root = nullptr;
    vector<TreeNode*> secLastLevel, lastLevel;
    int idxLastUsed = 0;
    CBTInserter(TreeNode* root_) {
        root=root_;
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()>0) {
            int count = q.size();
            vector<TreeNode *> nodesOnLevel;
            bool foundLastLevel=false;
            for(int i=0;i<count;i++){
                auto node = q.front();
                q.pop();
                nodesOnLevel.push_back(node);
                
                if(node->left == nullptr or node->right == nullptr)
                    foundLastLevel = true;
                
                if(node->left != nullptr)
                    q.push(node->left);
                if(node->right != nullptr)
                    q.push(node->right);
            }
            secLastLevel=nodesOnLevel;
            if(foundLastLevel) break;
        }
        for(int i=0;i<secLastLevel.size();i++){
            if(secLastLevel[i]->left != nullptr){
                lastLevel.push_back(secLastLevel[i]->left);
            }
            if(secLastLevel[i]->right != nullptr){
                lastLevel.push_back(secLastLevel[i]->right);
            }
            if(secLastLevel[i]->left == nullptr or secLastLevel[i]->right == nullptr){
                idxLastUsed=i;
                break;
            }
        }
    }
    
    int insert(int val) {
        
        if(secLastLevel[idxLastUsed]->left == nullptr){
            
            secLastLevel[idxLastUsed]->left = new TreeNode(val);
            lastLevel.push_back(secLastLevel[idxLastUsed]->left);
            return secLastLevel[idxLastUsed]->val;
            
        }else if(secLastLevel[idxLastUsed]->right == nullptr){
            
            secLastLevel[idxLastUsed]->right = new TreeNode(val);
            lastLevel.push_back(secLastLevel[idxLastUsed]->right);
            return secLastLevel[idxLastUsed]->val;
            
        }
        idxLastUsed++;
        if(idxLastUsed >= secLastLevel.size()){
            secLastLevel = lastLevel;
            lastLevel.clear();
            idxLastUsed=0;
        }
        return insert(val);
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */