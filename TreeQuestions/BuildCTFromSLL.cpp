#include <cstddef>

using namespace std;


//The structure of Link list Node is as follows
struct Node
{
    int data;
    struct node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
//The structure of TreeNode is as follows
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

class BuildCTFromSll{
public:
    //N stands for number of nodes in the given sll
    //Works in a preorder fashion and links the children to the parent in place
    void generateCompleteTree(TreeNode*& parentNode, TreeNode*& currNode, int currIndex, bool isLeft, int arr[], int n){
        TreeNode* nullRef = nullptr;
        if(parentNode == NULL){
            //given currNode is the root node we have been given in the convert function
            currNode =  new TreeNode(arr[currIndex]);
            int leftIndex = currIndex * 2 + 1;
            int rightIndex = leftIndex + 1;

            if(rightIndex < n){
                generateCompleteTree(currNode, nullRef, leftIndex, true, arr, n);
                generateCompleteTree(currNode, nullRef, rightIndex, false, arr, n);
            }
            else if(leftIndex < n){
                generateCompleteTree(currNode, nullRef, leftIndex, true, arr, n);
            }
        }
        else{
            //create the currNode and link it to its parent
            currNode = new TreeNode(arr[currIndex]);
            //cout << "Is left is " << isLeft << endl;
            if(isLeft){
                parentNode->left = currNode;
            }
            else{
                parentNode->right = currNode;
            }
            //keep searching through the further childs if they exist
            int leftIndex = currIndex * 2 + 1;
            int rightIndex = leftIndex + 1;
            if(rightIndex < n){
                generateCompleteTree(currNode, nullRef, leftIndex, true, arr, n);
                generateCompleteTree(currNode, nullRef, rightIndex, false, arr, n);
            }
            else if(leftIndex < n){
                generateCompleteTree(currNode, nullRef, leftIndex, true, arr, n);
            }

        }
    }
    //Function to make binary tree from linked list.
    void convert(Node *head, TreeNode *&root) {
        // Your code here

        if(head == NULL){
            root = nullptr;
        }
        else{
            //create an array from the given sll so as to have easier access in the long run
            int* arr = nullptr;
            int length = 0;
            Node* currNode = head;
            while(currNode != NULL){
                length++;
                currNode = currNode->next;
            }
            arr = new int[length];
            currNode = head;
            for(int i = 0; i < length; i++, currNode = currNode->next){
                arr[i] = currNode->data;
            }
            int rootIndex = 0;
            TreeNode* nullRef = nullptr;
            generateCompleteTree(nullRef, root, rootIndex, true, arr, length);
            //deallocate the arr so as to avoid memory leak
            delete[] arr;
        }
    }
};
