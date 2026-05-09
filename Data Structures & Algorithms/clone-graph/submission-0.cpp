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
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        map<Node*, Node*> index;
        map<Node*, Node*> index_b;
        Node* new_g = new Node(1);
        index[new_g] = node;
        index_b[node] = new_g;

        queue<Node*> nodes;
        nodes.push(new_g);

        while(!nodes.empty()){
            auto curr = nodes.front();
            nodes.pop();

            auto old_curr = index[curr];

            for(auto nodek : old_curr -> neighbors){
                if(index_b.count(nodek)) curr->neighbors.push_back(index_b[nodek]);
                else{
                    Node* new_node = new Node(nodek->val);
                    curr->neighbors.push_back(new_node);
                    nodes.push(new_node);
                    index[new_node] = nodek;
                    index_b[nodek] = new_node;
                }
            }
        }

        return new_g;
    }
};
