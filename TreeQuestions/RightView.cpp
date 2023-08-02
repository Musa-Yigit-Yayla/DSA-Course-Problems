#include <vector>
#include <cstddef>
#include <cmath>

using namespace std;
struct Node
{
    int data;
    struct Node* left = nullptr;
    struct Node* right = nullptr;

    Node(int x){
        data = x;
    }
};

// Should return  right view of tree
class Solution{
private:
    int rightHeight = 0;
public:
    /*//Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       //Traverse the tree from right and update the data field of right height
       //Retrieve the total height of the tree
       //For every height starting from right height + 1 up to total height inorder traverse the tree
       //and only get the nodes which have  the current height, then get the last node from the traversal
       //and add it to the resulting array
       if(root == NULL){
           vector<int> emptyVector;
           return emptyVector;
       }

       vector<int> result = rightViewHelper(root);
       int totalHeight = height(root);
       //Node* rightMostNode = result.at(result.size() - 1);
       int currHeight = this->rightHeight;
       for(int i = this->rightHeight + 1; i <= totalHeight; i++){
           vector<int> currLevelNodes = this->inorderHeight(root, currHeight, i);
           int currRightMost = currLevelNodes.at(currLevelNodes.size() - 1);
           result.push_back(currRightMost);
           currHeight++;
       }
       return result;
    }
    //This function will add the right nodes up to the max height on the right side of our tree
    vector<int> rightViewHelper(Node* root){
        vector<int> result;
        if(root != NULL){
            this->rightHeight++;
            result.push_back(root->data);
            vector<int> rightSubtree = this->rightViewHelper(root->right);
            result.insert(result.end(), rightSubtree.begin(), rightSubtree.end());
        }
        return result;
    }*/
    vector<int> rightView(Node* root) {
        vector<int> result;
        rightViewHelper(root, 1, result);
        return result;
    }

    // Helper function to obtain right view elements.
    void rightViewHelper(Node* root, int currHeight, vector<int>& result) {
        if (root == NULL) {
            return;
        }

        if (currHeight > result.size()) {
            result.push_back(root->data);
        }

        // Traverse the right subtree first to get the rightmost nodes.
        rightViewHelper(root->right, currHeight + 1, result);
        rightViewHelper(root->left, currHeight + 1, result);
    }
    vector<int> inorderHeight(Node* root, int currHeight, const int keyHeight){
        vector<int> result;
        if(root != NULL){
            currHeight++;
            if(currHeight == keyHeight){
                result.push_back(root->data);
            }
            else{
                vector<int> leftTree = inorderHeight(root->left, currHeight, keyHeight);
                result = leftTree;
                vector<int> rightTree = inorderHeight(root->right, currHeight, keyHeight);
                result.insert(result.end(), rightTree.begin(), rightTree.end());
            }
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
};
