#include <cstddef>
#include <unordered_map>

using namespace std;
class BTFromParentArr{
public:
    //Function to construct binary tree from parent array.
    Node *createTree(int parent[], int n){
        // Your code here
        int* treeArr = new int[n];
        //locate the root index
        int rootIndex = -1;
        for(int i = 0; i < n; i++){
            if(parent[i] == -1){
                rootIndex = i;
                break;
            }
        }
        Node* root = nullptr;
        if(rootIndex != -1){
            root = new Node(rootIndex);
            treeArr[0] = rootIndex;
            unordered_map<int, bool> found;
            queue<int> q; //will be used to contain the uninserted vertices
            found.insert({rootIndex, true});
            //we will use the map to see whether a parent node has already been linked to a child
            for(int i = 0; i < n; i++){
                if(i != rootIndex){
                    if(found.find(i) == found.end()){
                        Node* newNode = new Node(i);
                        //index at this node is going to be linked to its parent as the left child
                        int parentIndex = parent[i];
                        Node* parentNode = this->getNode(root, parentIndex);
                        if(parentNode != NULL){
                            parentNode->left = newNode;
                        }
                        else{
                            delete newNode;
                            //insert the value to the queue so as to make insertion in the future
                            q.push(i);
                        }
                    }
                    else if(found.at(i)){
                        //insert as the right child
                        Node* newNode = new Node(i);
                        //parent is guaranteed to exist
                        int parentIndex = parent[i];
                        Node* parentNode = this->getNode(root, parentIndex);
                        parentNode->right = newNode;
                    }
                }
            }
            //traverse the queue elements and insert them to their corresponding parents
            while(!q.empty()){
                int front = q.front();
                q.pop();
                int parentIndex = parent[front];
                Node* parent = this->getNode(root, front);
                if(parent != NULL){
                    Node* newNode = new Node(front);
                    //insert accordingly
                    if(found.find(front) == found.end()){
                        //insert as the left child and mark as found
                        parent->left = newNode;
                        found.insert({front, false});
                    }
                    else if(found.at(front)){
                        parent->right = newNode;
                    }
                }
                else{
                    //enqueue the newly popped element back into the queue for later use
                    q.push(front);
                }
            }
        }
        return root;
    }
    Node* getNode(Node* currNode, int key){
        if(currNode != NULL){
            //unordered_map<int, bool> newFound;
            //found = newFound;
            if(currNode->data == key){
                return currNode;
            }
            Node* leftSearch = this->getNode(currNode->left, key);
            if(leftSearch != NULL){
                return leftSearch;
            }
            Node* rightSearch = this->getNode(currNode->right, key);
            if(rightSearch != NULL){
                return rightSearch;
            }

        }
        return nullptr;
    }
};
