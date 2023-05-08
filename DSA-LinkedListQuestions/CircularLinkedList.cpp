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
        Node* tailPrev = tail;
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

        //Retrieve headPrev, headNext, tailPrev, tailNext
        Node* headPrev = head->next;
        while(headPrev != head){
            headPrev = headPrev->next;
        }
        Node* tailPrev = tail->next;
        while(tailPrev != tail){
            tailPrev = tailPrev->next;
        }

        Node* result = this->reverseCircularHelper();
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
