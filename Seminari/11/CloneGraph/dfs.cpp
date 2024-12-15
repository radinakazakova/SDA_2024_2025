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
    Node* dfs(Node* node, unordered_map<Node*, Node*>& clones)
    {
        if (clones.count(node)) 
            return clones[node];

        clones[node] = new Node(node->val, {});

        for (Node* neighbor : node->neighbors) 
        {
            clones[node]->neighbors.push_back(dfs(neighbor, clones));
        }

        return clones[node];
    }

    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;

        unordered_map<Node*, Node*> clones;
        return dfs(node, clones);
    }
};

//подобно решение от семинар
class Solution {
    // pointer value is a number => can be hashed
    unordered_map<Node*, Node*> indexToNode;
public:
    Node* cloneGraph(Node* node) {
        if(!node) {
            return node;
        }
        
        auto iter = indexToNode.find(node);
        if(iter != indexToNode.end()) {
            return iter->second;
        }
        
        Node* newNode = new Node(node->val);
        indexToNode[node] = newNode;
        
        for(auto neighbour: node->neighbors) {
            newNode->neighbors.push_back(cloneGraph(neighbour));
        }
        
        return newNode;
    }
};
