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
    //Not thoroughly reliable, passed 600/603 test cases though.
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
    //Function to check whether all nodes of a tree have the value
    //equal to the sum of their child nodes.
    //returns 1 if the condition is satisfied, returns 0 otherwise
    int isSumProperty(Node *root){
        // Add your code here
        if(root != NULL){
            if(root->left != NULL && root->right != NULL){
                int currSum = root->left->data + root->right->data;
                if(currSum != root->data){
                    return 0;
                }
                else{
                    return isSumProperty(root->left) && isSumProperty(root->right);
                }
            }
            else if(root->left != NULL){
                if(root->data != root->left->data){
                    return 0;
                }
                else{
                    return isSumProperty(root->left);
                }
            }
            else if(root->right != NULL){
                if(root->data != root->right->data){
                    return 0;
                }
                else{
                    return isSumProperty(root->right);
                }
            }
        }
        return 1;
    }
     // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        if(node != NULL){
            Node* leftTree = node->left;
            node->left = node->right;
            node->right = leftTree;
            mirror(node->left);
            mirror(node->right);
        }
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here
        if(root != NULL){
            if(abs(this->height(root->left) - this->height(root->right)) > 1){
                return false;
            }
            else{
                return isBalanced(root->left) && isBalanced(root->right);
            }
        }
        return true;
    }
    //Function to check if S is a subtree of tree T.
    bool isSubTree(Node* T, Node* S)
    {
        // Your code here
        vector<int> vecT = this->postOrder(T);
        vector<int> vecS = this->postOrder(S);

        string t = "";
        string s = "";

        for(int i = 0; i < vecT.size(); i++){
            int curr = vecT.at(i);
            t += curr;
        }
        for(int i = 0; i < vecS.size(); i++){
            int curr = vecS.at(i);
            s += curr;
        }
        int sLength = s.size();
        for(int i = 0; i <= vecT.size() - vecS.size(); i++){
            string currStr = t.substr(i, sLength);
            if(currStr == s){
                return true;
            }
        }
        return false;
    }
};
