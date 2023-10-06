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
    
    void dfs(Node* copy,Node* node,vector<Node*> &visited){
        
        visited[copy->val] = copy;
        
        for(auto child : node->neighbors){
            if(visited[child->val] == NULL){
                Node* newNode = new Node(child->val);
                copy->neighbors.push_back(newNode);
                dfs(newNode,child,visited);
            }else{
                copy->neighbors.push_back(visited[child->val]);
            }
        }
        
    }
    
    
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        
        vector<Node*> visited(1000,NULL);
        Node* copy = new Node(node->val);
        dfs(copy,node,visited);
        return copy;
    }
};
