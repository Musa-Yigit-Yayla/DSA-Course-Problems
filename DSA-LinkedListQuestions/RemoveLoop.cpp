#include <unordered_map>
#include <cmath>
#include "Node.cpp"

using namespace std;
class RemoveLoop{
public:
    static const int i = (int)(pow(10, 5));
    static const int differenceCheck = 1000;
    //Function to remove a loop in the linked list.
    void removeLoop2(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        if(this->detectLoop(head)){
            unordered_map<int, int> map;
            Node* currNode = head;
            Node* prevNode = nullptr;
            int counter = 0;
            while(currNode != NULL && counter < i ){
                if(map.find(currNode->data) != map.end()){
                    map.at(currNode->data)++;
                }
                else{
                    map.insert({currNode->data, 1});
                }
                /*if(map.at(currNode->data) > 1){
                    prevNode->next = nullptr;
                    return;
                }*/
                prevNode = currNode;
                currNode = currNode->next;
                counter++;
            }
            if(currNode != NULL){
                //we ensured that the linked list is containing a loop
                //Now we have to find the first node in which we enter into the loop
                Node* loopEntrance = nullptr;

                Node* currNode = head;
                Node* prevNode = nullptr;
                while(currNode != NULL){
                    if(prevNode != NULL){
                        if(currNode->data - prevNode->data > differenceCheck){
                            loopEntrance = currNode;
                            break;
                        }
                    }
                    prevNode = currNode;
                    currNode = currNode->next;
                }

                //We can presume that loopEntrance is not nullptr
                Node* tail = this->getPrev(loopEntrance, loopEntrance->data);
                tail->next = nullptr;
            }
        }
    }
    //Searchs for the previous node of the node matching the given key in a linked list
    //Returns nullptr if no match is found
    //The node to be searched is assumed to be in acceptable bounds and it's assumed that if the list
    //is circular it contains the node certainly
    Node* getPrev(Node* head, int key){
        Node* returnValue = nullptr;
        Node* curr = head;
        Node* prev = nullptr;
        while(curr != NULL){
            if(prev != NULL && curr->data == key){
                returnValue = prev;
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        return returnValue;
    }
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        if(this->detectLoop(head)){
            unordered_map<int, int> map;
            Node* currNode = head;
            Node* prevNode = nullptr;
            while(currNode != NULL){
                //if(map.find(currNode->data) == map.end()){
                //    map.insert({currNode->data, 1});
                //}
                map.at(currNode->data)++;
                if(map.at(currNode->data) > 1){ //&&){
                    prevNode->next = nullptr;
                    return;
                }
                prevNode = currNode;
                currNode = currNode->next;
            }
        }
    }
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        // your code here
        /*Node* currNode = head;
        vector<int> foundValues;

        while(currNode != NULL){
            if(count(foundValues.begin(), foundValues.end(), currNode->data) != 0){
                return true;
            }
            else{
                foundValues.push_back(currNode->data);
            }
            currNode = currNode->next;
        }
        return false;
        */
        Node* slow = head;
        Node* fast = head;
        int counter = 0;
        while(slow != NULL && fast != NULL){
            if(counter != 0 && slow == fast){
                //loop has been detected
                return true;
            }
            slow = slow->next;
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
            }
            counter++;
        }
        return false;
    }
    //Function to swap elements pairwise.
    struct Node* pairwise_swap(struct Node* head)
    {
        // your code here
        Node* currNode = head;
        Node* prevNode = nullptr;
        Node* newHead = nullptr;
        while(currNode != NULL && currNode->next != NULL){
            Node* currNext =currNode->next;
            currNode->next = currNext->next;
            currNext->next = currNode;
            if(prevNode != NULL){
                prevNode->next = currNext;
            }
            else{
                newHead = currNext;
            }
            prevNode = currNode;
            currNode = currNode->next;
        }
        return newHead;
    }
};
