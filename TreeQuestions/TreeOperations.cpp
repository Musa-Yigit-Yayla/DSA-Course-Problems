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
    // Function to insert a node in a BST.
    Node* insert(Node* root, int key) {
        // Your code here
        Node* newRoot = root;
        Node* currNode = root;
        Node* prevNode = nullptr;
        while(currNode != NULL){
            prevNode = currNode;
            if(currNode->data < key){
                currNode = currNode->right;
            }
            else if(currNode->data > key){
                currNode = currNode->left;
            }
            else{
                return newRoot;
            }
        }
        Node* newNode = new Node(key);
        if(prevNode->data < key){
            prevNode->right = newNode;
        }
        else{
            prevNode->left = newNode;
        }
        return newRoot;
    }
    // Function to return a list containing the inorder traversal of the BST.
    vector<int> inOrder(Node *root) {
        // code here
        vector<int> vec;
        if(root != NULL){
            vector<int> leftTree = inOrder(root->left);
            //push the children in the left subtree
            for(int i: leftTree){
                vec.push_back(i);
            }
            //push the current node
            vec.push_back(root->data);
            vector<int> rightTree = inOrder(root->right);
            //push the right subtree's children
            for(int i: rightTree){
                vec.push_back(i);
            }
        }
        return vec;
    }
    // Function to return the ceil of given number in BST.
    int findCeil(Node* root, int input) {
        if (root == NULL){
            return -1;
        }
        int ceil = -1;
        Node* currNode = root;
        while(currNode != NULL){
            int currValue = currNode->data;
            if(currValue < input){
                //search right subtree
                currNode = currNode->right;
            }
            else if(currValue == input){
                return currValue;
            }
            else{
                ceil = currValue;
                currNode = currNode->left;
            }
        }
        return ceil;
    }
};
