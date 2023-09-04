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
            found.insert({rootIndex, true});
            //we will use the map to see whether a parent node has already been linked to a child
            for(int i = 0; i < n; i++){
                if(i != rootIndex){
                    if(found.find(i) != found.end()){
                        if(!found.at(i)){
                            //index at this node is going to be linked to its parent as the left child

                        }
                    }
                }
            }
        }
        //
    }
    Node* getNode(Node* currNode, int key){
        if(currNode != NULL){
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
