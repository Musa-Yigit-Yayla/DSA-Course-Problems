#include <cstddef>
#include <unordered_map>

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
        Node* prev = nullptr;
        Node* curr = nullptr;
        int length = 0;
        while(head != NULL){
            curr = new Node(head->data);
            if(length == 0){
                newHead = curr;
            }
            else{
                prev->next = curr;
            }
            head = head->next;
            prev = curr;
            curr = curr->next;
            length++;
        }
        if(length != 0){
            //Node* newNodes[length];
            head = newHead;
            Node* originalHead = initialHead;
            unordered_map<Node*, Node*> map; // key is the original list node, value is the copy list node correspondance


            for(int i = 0; i < length; i++){
                //newNodes[i] = head;
                map[originalHead] = head;
                originalHead = originalHead->next;
                head = head->next;
            }
            head = initialHead;

            while(head != NULL){
                map[head]->arb = map[head->arb];
                head = head->next;
            }
        }
        return newHead;
    }
    //gets the first occurence of the node with the given data if exists
    Node* getNode(const Node* head, int data){
        Node* curr = const_cast<Node*>(head);
        Node* result = nullptr;
        while(curr != NULL){
            if(curr->data == data){
                result = curr;
                break;
            }
            curr = curr->next;
        }
        return result;
    }

};
