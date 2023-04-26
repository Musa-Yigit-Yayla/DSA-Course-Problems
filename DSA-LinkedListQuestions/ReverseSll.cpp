#include "Node.cpp"
#include <iostream>

using namespace std;
class ReverseSll{
public:
    //Function to reverse a linked list.
    Node* reverseList(Node *head)
    {
        // code here
        // return head of reversed list
        Node* initialHead = head;
        Node* resultHead;
        int length = 0;
        while(head != NULL){
            head = head->next;
            length++;
        }
        head = initialHead;
        if(length == 0 || length == 1){
            return head;
        }
        Node* low = NULL;
        Node* high = NULL;
        int highIndex = length - 1;
        for(int i = 0; i < length / 2; i++){
            if(i == 0){
                //swap head and last
                Node* last = this->nodeAt(head, length - 1);
                Node* headNext = head->next;
                Node* lastPrev = this->nodeAt(head, length - 2);

                lastPrev->next = head;
                last->next = headNext;

                resultHead = last;

                low = last;
                high = head;
                head = resultHead;
            }
            else{
                //swap low and high
                Node* lowNext = low->next;
                Node* lowPrev = this->nodeAt(head, length - highIndex - 1); // MIGHT BE PROBLEMATIC INDEXING !!!!
                Node* highPrev = this->nodeAt(head, highIndex - 1);
                Node* highNext = high->next;

                lowPrev->next = high;
                high->next = lowNext;
                highPrev->next =low;
                low->next = highNext;
            }
            low = low->next;
            high = this->nodeAt(head, --highIndex);
        }
        return resultHead;

    }
    //Does no bounds checking
    //User is responsible of ensuring that the position is valid
    //0 based indexing
    Node* nodeAt(Node* head, int pos){
        if(pos == 0){
            return head;
        }
        Node* initialHead = head;
        //cout << "nodeAt function" << endl;
        for(int i = 0; i < pos; i++){
            //cout << head->data << endl;
            head = head->next;
        }
        Node* result = head;
        //head = initialHead;
        return result;
    }

};
