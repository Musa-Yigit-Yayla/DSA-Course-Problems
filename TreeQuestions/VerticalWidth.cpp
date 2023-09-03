#include <cstddef>

using namespace std;
struct{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void preorderHelper(Node* curr, int currWidth, int& leftMost, int& rightMost);
//Function to find the vertical width of a Binary Tree.
int verticalWidth(Node* root){
    int leftMost = 0;
    int rightMost = 0;

    if(root == NULL){
        return 0;
    }
    preorderHelper(root, 0, leftMost, rightMost);
    return abs(rightMost - leftMost) + 1;
}
void preorderHelper(Node* curr, int currWidth, int& leftMost, int& rightMost){
    if(curr != NULL){
        //update the leftMost and rightMost when appropriate
        if(currWidth < leftMost){
            leftMost = currWidth;
        }
        else if(currWidth > rightMost){
            rightMost = currWidth;
        }
        preorderHelper(curr->left, currWidth - 1, leftMost, rightMost);
        preorderHelper(curr->right, currWidth + 1, leftMost, rightMost);
    }
}
