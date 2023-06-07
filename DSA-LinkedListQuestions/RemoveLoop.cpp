#include <unordered_map>
#include "Node.cpp"

using namespace std;
class RemoveLoop{
    public:
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
                if(map.at(currNode->data) > 1 &&){
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
};
