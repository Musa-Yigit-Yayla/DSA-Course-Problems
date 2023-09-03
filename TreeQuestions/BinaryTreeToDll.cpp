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
    Node *bTreeToCList(Node *root){
        Node* start = this->bToDLL(root);
        if(start == NULL){
            return nullptr;
        }
        //get to the latest node in the current dll using right pointers to traverse
        Node* currNode = start;
        while(currNode != NULL){
            if(currNode->right == NULL){
                //link the terminating node back to the beginning node
                currNode->right = start;
                start->left = currNode;
                break;
            }
            else{
                currNode = currNode->right;
            }
        }
        return start;

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
