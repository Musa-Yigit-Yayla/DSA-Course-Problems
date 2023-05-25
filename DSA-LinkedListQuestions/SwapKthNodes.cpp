#include "Node.cpp"
#include <iostream>
#include <cstddef>

using namespace std;
class SwapKthNodes{
public:
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
        Node* result = initialHead;
        //head = initialHead;
        return result;
}

//Function to swap Kth node from beginning and end in a linked list.
//This method is not thoroughly functional, try and avoid using if that's not possible approach with attention.
Node* swapkthnode(Node* head, int n, int k)
{
    return this->swapNodes(head, k, n - k);
    /*// Your Code here
    if(n <= 1){
        return head;
    }
    Node* initialHead = head;

    int length = 0;
    while(initialHead != NULL){
        length++;
        initialHead = initialHead->next;
    }
    if(k == 1){
        //swap the head with end
        Node* headNext = head->next;
        Node* last = nodeAt(head, length - 1);
        Node* lastPrev = nodeAt(head, length - 2);
        lastPrev->next = head;
        head->next = nullptr;
        last->next =headNext;
        head = last;

    }
    else if(length - k != k){
        Node* low = nodeAt(head, k);

        Node* lowPrev = nullptr;
        Node* highNext = nullptr;
        if(k - 2 >= 0){
            lowPrev = nodeAt(head, k - 1);
            highNext = nodeAt(head, length - (k + 1));
        }
        Node* lowNext = nodeAt(head, k + 1);

        Node* high = nodeAt(head, length - (k));
        Node* highPrev = nodeAt(head, length - k - 1); //HIGHPREV VE LOWNEXTE BAK INDEXLERE

        if(lowPrev == NULL){
            highPrev->next = low;
            high->next = lowNext;
            low->next = nullptr;
        }
        else{
            lowPrev->next = high;
            high->next = lowNext;

            highPrev->next = low;
            low->next = highNext;
        }
    }
    return head;*/
}
    void printList(Node* head){
        Node* currNode = head;
        while(currNode != NULL){
            cout << currNode->data << " ";
            currNode = currNode->next;
        }
        cout << endl;
    }
    //Swaps the nodes in a regular sll with the given indexes
    //parameter indexing must belong to the subset of the range from 0 to length - 1
    //Subsequently returns the head node
    //If swap is unsuccessful also returns the head node
    Node* swapNodes(Node* head, int i1, int i2){
        //initially retrieve the node length
        Node* currNode = head;
        int length = 0;
        while(currNode != NULL){
            length++;
            currNode = currNode->next;
        }
        //perform index validation
        if(i1 >= length || i1 < 0 || i2 >= length || i2 < 0 || i1 == i2){
            return head;
        }
        bool swapHead = false;
        bool swapTail = false;
        if(i1 == 0 || i2 == 0){
            swapHead = true;
        }
        if(i1 == length - 1 || i2 == length - 1){
            swapTail = true;
        }
        if(swapHead && !swapTail){
            Node* headNode = head;
            Node* otherNode = nullptr;
            bool isI1Head  = false;
            if(i1 == 0){
                otherNode = this->nodeAt(head, i1);
                isI1Head = true;
            }
            else{
                otherNode = this->nodeAt(head, i2);
            }
            Node* otherPrev = nullptr;
            Node* otherNext = nullptr;
            if(isI1Head){
                otherPrev = this->nodeAt(head, i1 - 1);
                otherNext = this->nodeAt(head, i1 + 1);
            }
            else{
                otherPrev = this->nodeAt(head, i2 - 1);
                otherNext = this->nodeAt(head, i2 + 1);
            }
            Node* headNext = head->next;
            otherNode->next = headNext;
            otherPrev->next = head;
            head->next = otherNode->next;
            return otherNode;
        }
        else if(!swapHead && swapTail){
            Node* tailNode = this->nodeAt(head, length - 1);
            Node* tailPrev = this->nodeAt(head, length - 2);
            Node* otherNode = nullptr;
            Node* otherPrev = nullptr;
            Node* otherNext = nullptr;

            bool isI1Tail = false;
            if(i1 == length - 1){
                otherNode = this->nodeAt(head, i1);
                otherPrev = this->nodeAt(head, i1 - 1);
                otherNext = this->nodeAt(head, i1 + 1);
                isI1Tail = true;
            }
            else{
                otherNode = this->nodeAt(head, i2);
                otherPrev = this->nodeAt(head, i2 - 1);
                otherNext = this->nodeAt(head, i2 + 1);
            }
            otherPrev->next = tailNode;
            tailNode->next = otherNext;
            tailPrev->next = otherNode;
            return head;
        }
        else if(swapHead && swapTail){
            if(length == 2){
                Node* headNext = head->next;
                headNext->next = head;
                head->next = nullptr;
                return head;
            }
            Node* headNode = nullptr;
            Node* headNext = nullptr;
            Node* tailNode = nullptr;
            Node* tailPrev = nullptr;
            if(i1 == 0){
                headNode = this->nodeAt(head, i1);
                headNext = this->nodeAt(head, i1 + 1);
                tailNode = this->nodeAt(head, length - 1);
                tailPrev = this->nodeAt(head, length - 2);
            }
            else{//this block satisfies that i2 is the head node index
                headNode = this->nodeAt(head, i2);
                headNext = this->nodeAt(head, i2 + 1);
                tailNode = this->nodeAt(head, length - 1);
                tailPrev = this->nodeAt(head, length - 2);
            }
            tailNode->next = headNext;
            tailNode->prev = headNode;
            headNode->next = nullptr;
            return tailNode;
        }
        else{//we are swapping some inner nodes, proceed accordingly
            Node* n1 = this->nodeAt(head, i1);
            Node* n1Prev = this->nodeAt(head, i1 - 1);
            Node* n1Next = this->nodeAt(head, i1 + 1);
            Node* n2 = this->nodeAt(head, i2);
            Node* n2Prev = this->nodeAt(head, i2 -1);
            Node* n2Next = this->nodeAt(head, i2 + 1);

            //it would be the same procedure whether we have n1Next == n2Prev or not
            n1Prev->next = n2;
            n2->next = n1Next;

            n2Prev->next = n1;
            n1->next = n2Next;

            return head;
        }
    }
};
