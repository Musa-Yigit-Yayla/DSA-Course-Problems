#include "Node.cpp"
#include <unordered_map>

class RemoveDuplicatesSll{
public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates(Node *head)
    {
     // your code goes here
     unordered_map<int, int> occurences;
     unordered_map<int, bool> isUsed;

     //count the occurences of elements in the given sll
     Node* currNode = head;
     while(currNode != NULL){
         if(occurences.count(currNode->data) == 0){
             occurences.insert({currNode->data, 1});
             isUsed.insert({currNode->data, false});
         }
         else{
             occurences.at(currNode->data)++;
         }
         currNode = currNode->next;
     }

     //traverse the given linked list and select the unused items
     Node* newList = new Node(INT_MIN);
     Node* newListNext = nullptr;
     currNode = head;

     while(currNode != NULL){
         int currData = currNode->data;
         if(!isUsed.at(currData)){
             Node* newNode = new Node(currData);
             if(newListNext == NULL){
                 newListNext = newNode;
                 newList->next = newListNext;
             }
             else{
                 newListNext->next = newNode;
                 newListNext = newListNext->next;
             }

             isUsed.at(currData) = true;
         }
         currNode = currNode->next;
     }
     Node* returnValue = newList->next;
     delete newList;
     return returnValue;

    }
};
