#include <cstddef>

using namespace std;
struct Node{
    Node* left = nullptr;
    Node* right = nullptr;
    int data;
    Node(int data){
        this->data = data;
    }
};

class TreeOperations{
public:
    bool search(Node* root, int x) {
        // Your code here
        Node* currNode = root;
        bool returnValue = false;
        while(currNode != NULL){
            int comparison = x- currNode->data;
            if(comparison == 0){
                returnValue = true;
                break;
            }
            else if(comparison < 0){
                //search the left subtree
                currNode = currNode->left;
            }
            else{
                //search the right subtree
                currNode = currNode->right;
            }
        }
        return returnValue;
    }
    int minValue(Node* root) {
        // Code here
        //minimum element is the leftmost child, hence retrieve the leftmost child
        Node* currNode = root;
        while(currNode != NULL){
            if(currNode->left == NULL){
                return currNode->data;
            }
            currNode = currNode->left;
        }
        return -1;
    }

};
