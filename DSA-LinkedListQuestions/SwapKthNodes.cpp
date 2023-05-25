#include "Node.cpp"

using namespace std;
class SwapKthNodes{
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

//Function to swap Kth node from beginning and end in a linked list.
Node* swapkthnode(Node* head, int n, int k)
{
    // Your Code here
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
        Node* last = nodeAt(head, length);
        Node* lastPrev = nodeAt(head, length - 1);
        lastPrev->next = head;
        head->next = nullptr;
        last->next =headNext;
        head = last;

    }
    else if(length - k != k){
        Node* low = nodeAt(head, k - 1);

        Node* lowPrev = nullptr;
        Node* highNext = nullptr;
        if(k - 2 >= 0){
            lowPrev = nodeAt(head, k - 2);
            highNext = nodeAt(head, length - (k - 2));
        }
        Node* lowNext = nodeAt(head, k);

        Node* high = nodeAt(head, length - (k - 1));
        Node* highPrev = nodeAt(head, length - k);

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
    return head;
}
};
