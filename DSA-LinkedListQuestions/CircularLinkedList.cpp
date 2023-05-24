#include "Node.cpp"
#include <iostream>

class CircularLinkedList{
public:
    Node* reverseCircularLinkedList(Node* head){
        //first retrieve the tail node if the list is not empty or has only 1 element
        if(head == NULL || head->next == head){
            return head;
        }
        Node* tail = head;
        int length = 1;
        Node* tailPrev = head;
        while(tail->next != head){
            tailPrev = tail;
            tail = tail->next;
            length++;
        }
        //Do the initial swap in here, then you must do the remaining in the below method
        Node* headNext = head->next;
        tail->next = headNext;
        head->next = tail;
        tailPrev->next = head;
        return this->reverseCircularHelper(tail, head, length - 2);

    }
    Node* reverseCircularHelper(Node* head, Node* tail, int length){
        if(length == 0 || length == 1){
            return head; //might be problematic
        }
        //In this method we can consider the remaining part of the linked list as a linear linked list except the tail has a next node
        //Swap head and tail, then decrement the length by 2

        else if(length == 2){
            return tail;
        }
        //Retrieve headPrev, headNext, tailPrev, tailNext
        Node* headPrev = head;
        while(headPrev->next != head){
            headPrev = headPrev->next;
        }
        Node* tailPrev = tail;
        while(tailPrev->next != tail){
            tailPrev = tailPrev->next;
        }

        Node* headNext = head->next;
        Node* tailNext = tail->next;

        headPrev->next = tail;
        tail->next = headNext;

        tailPrev->next = head;
        head->next = tailNext;

        Node* result = this->reverseCircularHelper(tail, head, length - 2);
        return result;
    }
    //If the given node already exists in our list, then we must not insert and return nullptr
    //Otherwise we must insert at the beginning by preserving the circular property of our list and return the new head
    Node* insertAtBeginning(Node* head, Node* givenNode){

        if(head == NULL){
            head = givenNode;
            head->next = head;
            return head;
        }
        int listLength = this->getListLength(head);
        if(listLength == 1){
            //only one node exists before the insertion operation
            givenNode->next = head;
            head->next = givenNode;
            return givenNode;
        }
        //traverse the node to check whether we have a node with the same data of the givenNode's
        Node* currNode = head;
        Node* prevNode = nullptr;
        int counter = 0;
        int givenData = givenNode->data;
        while(currNode != head || counter == 0){
            if(currNode->data == givenData){
                return nullptr;
            }
            counter++;
            prevNode = currNode;
            currNode = currNode->next;
        }
        //prevNode is the node pointing to our current head
        prevNode->next = givenNode;
        givenNode->next = head;
        head = givenNode;
        return head;
    }
    Node* insertAtEnd(Node* head, Node* givenNode){
        int listLength = this->getListLength(head);
        if(listLength == 0 || listLength == 1){
            return this->insertAtBeginning(head, givenNode);
        }
        //we must traverse the list and retain the prevNode of head
        Node* currNode = head;
        Node* prevNode = nullptr;
        int counter = 0;
        while(currNode != head || counter == 0){
            prevNode = currNode;
            currNode = currNode->next;
            counter++;
        }
        prevNode->next = givenNode;
        givenNode->next = head;
        return givenNode;
    }
    //Returns the length of the given circular linked list
    int getListLength(Node* head){
        Node* currNode = head;
        if(head == NULL){
            return 0;
        }
        int length = 0;
        Node* currNode = head;
        while(currNode != NULL){
            currNode = currNode->next;
            length++
        }
        return length;
    }
    void printList(Node* head){
        if(head == NULL){
            return;
        }
        Node* curr = head;
        do{
            cout << curr->data << endl;
            curr = curr->next;
        }while(curr != head);
    }
};
