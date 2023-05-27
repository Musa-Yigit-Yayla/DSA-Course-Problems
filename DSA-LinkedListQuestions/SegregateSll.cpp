#include <unordered_map>
#include "Node.cpp"

using namespace std;
class SegregateSll{
public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {

        // Add code here
        unordered_map<int, int> map;

        Node* currNode = head;
        while(currNode != NULL){
            int value = currNode->data;

            switch(value){
                case 0:
                    if(map.count(0) == 0){
                        map.insert({0, 1});
                    }
                    map.at(0)++; break;
                case 1:
                    if(map.count(1) == 0){
                        map.insert({1, 1});
                    }
                    map.at(1)++; break;

                case 2:
                    if(map.count(2) == 0){
                        map.insert({2, 1});
                    }
                     map.at(2)++; break;
            }
            currNode = currNode->next;
        }
        int zeroLength = map.at(0);
        int oneLength = map.at(1);
        int twoLength = map.at(2);

        Node* newList = nullptr;
        Node* initialNewList = nullptr;
        bool isAdded = false;
        for(int i = 0; i < zeroLength; i++){
            if(newList == nullptr){
                if(!isAdded){
                    newList = new Node(0);
                    initialNewList = newList;
                }
                else{
                    newList = new Node(0);
                    //newList = newList->next;
                }
                isAdded = true;
            }
            newList = newList->next;
        }
        for(int i = 0; i < oneLength; i++){
            if(newList == nullptr){
                if(!isAdded){
                    newList = new Node(1);
                    initialNewList = newList;
                }
                else{
                    newList = new Node(1);
                    //newList = newList->next;
                }
                isAdded = true;
            }
            newList = newList->next;
        }
        for(int i = 0; i < twoLength; i++){
            if(newList == nullptr){
                if(!isAdded){
                    newList = new Node(2);
                    initialNewList = newList;
                }
                else{
                    newList = new Node(2);
                    //newList = newList->next;
                }
                isAdded = true;
            }
            newList = newList->next;
        }
        return initialNewList;
    }

};
