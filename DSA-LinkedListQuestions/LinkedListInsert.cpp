#include <cstddef>
#include "LoopLength.cpp"

using namespace std;

/*struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class LinkedListInsert{
  public:
    //Function to insert a node at the beginning of the linked list.
    Node *insertAtBegining(Node *head, int x) {
       // Your code here
       Node* newNode = new Node(x);
       newNode->next = head;
       return newNode;
    }


    //Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)  {
       // Your code here
       int counter = 0;

       Node* initialHead = head;
       Node* prevNode = head;
       Node* newNode = new Node(x);
       while(head != NULL){
           counter++;
           prevNode = head;
           head = head->next;
       }
       if(counter == 0){
           newNode->next = NULL;
           head = newNode;
       }
       else{
           prevNode->next = newNode;
           return initialHead;
       }
       return head;
    }
};
