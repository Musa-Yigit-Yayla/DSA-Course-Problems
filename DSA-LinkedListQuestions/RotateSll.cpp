#include "Node.cpp"
#include <cstddef>

class RotateSll{
public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // Your code here
        if(k <= 0){
            return head;
        }
        int listLength = 0;
        Node* currHead = head;
        Node* tailNode = nullptr;
        while(currHead != NULL){
            listLength++;
            if(currHead->next == NULL){
                tailNode = currHead;
            }
            currHead = currHead->next;
        }
        if(listLength <= k){
            return head;
        }
        //valid list and valid k
        int rotationIndex = k - 1;
        Node* newHead = this->nodeAt(head, rotationIndex + 1);
        Node* newLast = this->nodeAt(head, rotationIndex);
        tailNode->next = head;
        newLast->next = nullptr;
        return newHead;
    }
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

