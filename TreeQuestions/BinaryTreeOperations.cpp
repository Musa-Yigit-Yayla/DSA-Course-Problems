#include <cstddef>
#include <vector>
#include <cmath>

using namespace std;
struct Node{
    Node* left = nullptr;
    Node* right = nullptr;
    int data;
    Node(int data){
        this->data = data;
    }
};
class BinaryTreeOperations{
public:
    //Function to return a list containing the preorder traversal of the tree.
    vector <int> preorder(Node* root){
      vector<int> result;
      if(root != NULL){
          result.push_back(root->data);
          vector<int> leftTree = preorder(root->left);
          vector<int> rightTree = preorder(root->right);
          result.insert(result.end(), leftTree.begin(), leftTree.end());
          result.insert(result.end(), rightTree.begin(), rightTree.end());
      }
      return result;
    }
     // Function to return a list containing the inorder traversal of the tree.
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
    //Function to return a list containing the postorder traversal of the tree.
    vector <int> postOrder(Node* root){
        vector<int> result;
          if(root != NULL){
              vector<int> leftTree = postOrder(root->left);
              result = leftTree;
              vector<int> rightTree = postOrder(root->right);
              //result.insert(result.end(), leftTree.begin(), leftTree.end());
              result.insert(result.end(), rightTree.begin(), rightTree.end());
              result.push_back(root->data);

          }
          return result;
    }
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here
        int result = 0;
        if(node != NULL){
            int leftHeight = height(node->left);
            int rightHeight = height(node->right);
            int maxHeight = max(leftHeight, rightHeight);
            result = maxHeight + 1;
        }
        return result;
    }
    //Function to return a list containing elements of left view of the binary tree.
    vector<int> leftView(Node *root)
    {
       // Your code here
       vector<int> result;
       if(root != NULL && root->left == NULL){
           result.push_back(root->data);
           vector<int> rightSubtree = leftView(root->right);
           result.insert(result.end(), rightSubtree.begin(), rightSubtree.end());
       }
       else if(root != NULL){
           result.push_back(root->data);
           vector<int> leftSubtree = leftView(root->left);
           result.insert(result.end(), leftSubtree.begin(), leftSubtree.end());
       }
       return result;
    }
};
