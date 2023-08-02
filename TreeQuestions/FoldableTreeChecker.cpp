#include <cstddef>

using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

bool isFoldableHelper(Node* leftSibling, Node* rightSibling) {
    if (leftSibling == NULL && rightSibling == NULL) {
        return true; // base case: both siblings are NULL, and the tree is foldable.
    }

    if (leftSibling == NULL || rightSibling == NULL) {
        return false; // base case: one sibling is NULL, and the tree is not foldable.
    }

    // Check if the subtrees are foldable and they are mirror images of each other.
    return isFoldableHelper(leftSibling->left, rightSibling->right) &&
           isFoldableHelper(leftSibling->right, rightSibling->left);
}

// Function to check whether a binary tree is foldable or not.
bool IsFoldable(Node* root) {
    if (root == NULL) {
        return true; // An empty tree is considered foldable.
    }

    return isFoldableHelper(root->left, root->right);
}
