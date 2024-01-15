Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

#include <climits>
#include <cmath>

class FindClosestBST{
public:
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
    int minDiff(Node *root, int K){
        int result = INT_MAX;
        //apply binary search and keep track of the minimum absolute difference between K and the nodes
        Node* currNode = root;
        while(currNode != NULL){
            int diff = K - currNode->data;
            int absDiff = abs(diff);
            if(absDiff < result){
                result = absDiff;
            }
            if(diff < 0){
                //search left
                currNode = currNode->left;
            }
            else if(diff == 0){
                //K found
                break;
            }
            else{
                //search right
                currNode = currNode->right;
            }
        }
        return result;
    }
};
