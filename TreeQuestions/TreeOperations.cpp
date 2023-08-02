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
    vector<int> inOrder(Node* root) {
      vector<int> result;
      if(root != NULL){
          vector<int> leftTree = inOrder(root->left);
          result = leftTree;
          result.push_back(root->data);
          vector<int> rightTree = inOrder(root->right);
          //result.insert(result.end(), leftTree.begin(), leftTree.end());
          result.insert(result.end(), rightTree.begin(), rightTree.end());
      }
      return result;
    }
    Node* getNodeByValue(Node* root, const int data){
        if(root != NULL){
            if(root->data == data){
                return root;
            }
            else{
                Node* leftSubtree = getNodeByValue(root->left, data);
                Node* rightSubtree = getNodeByValue(root->right, data);
                if(leftSubtree != NULL){
                    return leftSubtree;
                }
                else{
                    return rightSubtree;
                }
            }
        }
        return nullptr;
    }
    int median(Node *node,int k){
        //Your code here
        vector<int> vec = inOrder(node);
        if(k > vec.size()){
            return -1;
        }
        else{
            Node* currRoot = getNodeByValue(node, vec.at(k - 1));
            vector<int> subVec = inOrder(currRoot);
            int result;
            if(subVec.size() % 2 == 0){
                int i1 = subVec.size() / 2 - 1;
                int i2 = i1 + 1;
                result = (subVec.at(i1) + subVec.at(i2)) / 2;
            }
            else{
                result = subVec.at(subVec.size() / 2);
            }
            return result;
        }
    }
};
