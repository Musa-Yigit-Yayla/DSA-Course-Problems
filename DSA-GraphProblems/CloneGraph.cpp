//LeetCode graph problem

#include <cstddef>
#include <stack>
#include <vector>

using namespace std;
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


class CloneGraph {
private:
    vector<Node*> clonedNodes;

public:
    Node* cloneGraph(Node* node) {
        this->clonedNodes.clear(); // clear the previously obtained clonedNodes

        Node* clonedNode = nullptr;
        if (node != NULL) {
            // apply dfs on the given node
            clonedNode = new Node(node->val);
            this->clonedNodes.push_back(clonedNode); //clonedNodes will also serve as a visitedNodes vector

            stack<Node*> s;
            s.push(node);
            while(!s.empty()){
                Node* currNode = s.top();
                s.pop();


                //get the adjList of the current actual node and select unvisited nodes then push them into the stack
                for(int i = 0; i < currNode->neighbors.size(); i++){
                    Node* currAdj = currNode->neighbors.at(i);
                    if(!this->isVisited(currAdj->val)){
                        //instantiate a clone node and connect it to currNode bidirectionally
                        Node* currClone = new Node(currAdj->val);
                        currNode->neighbors.push_back(currClone);
                        currClone->neighbors.push_back(currNode);

                        //push the currClone onto the stack
                        s.push(currClone);

                        //mark the currClone as visited by pushing it to clonedNodes
                        this->clonedNodes.push_back(currClone);
                    }
                }
            }
        }
        return clonedNode;
    }
    //checks whether a given node has already been visited in the clonedNodes field
    bool isVisited(int nodeVal){
        bool found = false;
        for(int i = 0; i < this->clonedNodes.size(); i++){
            int currVal = this->clonedNodes.at(i)->val;
            if(currVal == nodeVal){
                found = true;
                break;
            }
        }
        return found;
    }
};
