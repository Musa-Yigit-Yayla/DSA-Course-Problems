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
 */

class MaxWidth{
  public:
    // Function to get the maximum width of a binary tree.
    int getMaxWidth(Node* root) {
        // Your code here
        if (root == nullptr) {
            return 0;
        }

        vector<int> levels; // Stores the number of nodes at each level
        getMaxWidthHelper(root, 1, levels);

        int maxWidth = 1; // The minimum width is always 1 (root node)
        for (int count : levels) {
            maxWidth = max(maxWidth, count);
        }

        return maxWidth;
    }

    // Function to find the height of a binary tree and count nodes at each level.
    void getMaxWidthHelper(Node* node, int level, vector<int>& levels) {
        if (node == nullptr) {
            return;
        }

        // Increase the size of levels vector to store the count for the current level.
        if (level > levels.size()) {
            levels.push_back(1);
        } else {
            levels[level - 1]++;
        }

        // Recursively traverse left and right subtrees.
        getMaxWidthHelper(node->left, level + 1, levels);
        getMaxWidthHelper(node->right, level + 1, levels);
    }
};
