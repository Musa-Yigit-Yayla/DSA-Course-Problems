#include <cstddef>

using namespace std;

struct Node{
public:
    int data;
    Node* next;
    Node* arb;

    Node(int x){
        this->data = x;
    }
};
class copyArbitraryList{
//initially traverse the linked list and create a regular sll by also having a map in which
    //holding each pointer'S arbitrary pointer's index, also create a built-in array holding each
    //and every pointer.

    public:
    Node *copyList(Node* head)
    {
        //Write your code here
        Node* initialHead = head;
        Node* newHead = nullptr;
        int counter = 0;
        if(head != NULL){
            Node* curr = nullptr;
            while(head != NULL){
                curr = new Node(head->data);
                if(head->next == NULL){
                    curr->next = nullptr;
                }
                else{
                    curr->next = new Node(head->next->data);
                }
                if(head->arb == NULL){
                    curr->arb = nullptr;
                }
                else{
                    curr->arb = new Node(head->arb->data);
                }
                if(counter == 0){
                    newHead = curr;
                }
                head = head->next;
                curr = curr->next;
                counter++;
            }
            //set arbitrary pointers
            /*head = initialHead;
            while(head != NULL){

            }*/
        }
        return newHead;
    }
    Node* copyList2(Node* head){
        Node* initialHead = head;
        Node* newHead = nullptr;
        Node* curr = nullptr;
        int length = 0;
        while(head != NULL){
            curr = new Node(head->data);
            if(length == 0){
                newHead = curr;
            }
            head = head->next;
            curr = curr->next;
            length++;
        }
        if(length != 0){
            Node* newNodes[length];
            head = newHead;
            for(int i = 0; i < length; i++){

            }
        }
        return newHead;
    }

};
