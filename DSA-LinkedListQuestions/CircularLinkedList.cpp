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
        while(tail->next != head){
            tail = tail->next;
        }

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
