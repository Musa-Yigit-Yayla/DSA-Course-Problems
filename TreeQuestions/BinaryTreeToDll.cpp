#include <vector>
#include <cstddef>

class BinaryTreeToDll{
public:
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root){

        if(root == NULL){
            return nullptr;
        }
        //left pointer is prev, right is next
        vector<Node*> nodeList; //will contain our nodes in their inorder ordering
        this->inorder(root, nodeList);
        for(int i = 1; i < nodeList.size(); i++){
            Node* prevNode = nodeList.at(i - 1);
            Node* currNode = nodeList.at(i);
            currNode->left = prevNode;
            prevNode->right = currNode;
        }
        return nodeList.at(0);
    }
    //Does not make any binding alternation to the pointers
    void inorder(Node* currNode, vector<Node*>& nodeList){
        if(currNode != NULL){
            this->inorder(currNode->left, nodeList);
            nodeList.push_back(currNode);
            this->inorder(currNode->right, nodeList);
        }
    }
};
