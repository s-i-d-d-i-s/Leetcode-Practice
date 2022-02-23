/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<int,Node*> visit;
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr;
        }
        Node * result = new Node(node->val);
        visit[node->val]=result;
        for(auto x:node->neighbors){
            if(visit.find(x->val)==visit.end())
                result->neighbors.push_back(cloneGraph(x));
            else
                result->neighbors.push_back(visit[x->val]);
        }
        return result;
    }
};