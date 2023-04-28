//#include "LoopLength.cpp"
//#include "LinkedListInsert.cpp"
//#include "ReverseSll.cpp"
#include "AddTwoLists.cpp"
#include <iostream>
/*struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/

using namespace std;
int main(){
    Node head(4);
    Node* next = new Node(3);
    head.next = next;
    next->next = new Node(2);
    next->next->next = new Node(5);
    next->next->next->next = new Node(6);
    next->next->next->next->next = new Node(7);

    Node* head2 = new Node(5);
    head2->next = new Node(7);
    head2->next->next = new Node(9);
    head2->next->next->next = new Node(9);
    head2->next->next->next->next = new Node(9);
    head2->next->next->next->next->next = new Node(8);
    head2->next->next->next->next->next->next = new Node(5);
    head2->next->next->next->next->next->next->next = new Node(5);
    head2->next->next->next->next->next->next->next->next = new Node(3);
    head2->next->next->next->next->next->next->next->next->next = new Node(9);
    head2->next->next->next->next->next->next->next->next->next->next = new Node(2);
    head2->next->next->next->next->next->next->next->next->next->next->next = new Node(9);
    head2->next->next->next->next->next->next->next->next->next->next->next->next = new Node(8);
    head2->next->next->next->next->next->next->next->next->next->next->next->next->next = new Node(7);
    int sllLength = 6;

    /*LoopLength ll;
    cout << ll.countNodesinLoop(&head) << endl;

    Node* n1 = new Node(13);
    Node* n2 = new Node(70);

    LinkedListInsert lli;
    lli.insertAtBegining(&n1);
    lli.insertAtEnd(&n2);*/


    AddTwoLists atl;
    Node* newList = atl.addTwoList(&head, head2);

    cout << newList->data << endl;
    cout << atl.nodeAt(&head, 3)->data << endl;
    cout << atl.nodeAt(&head, 2)->data << endl;

    /*Node* curr = head.next;
    for(int i = 0; i < sllLength - 1; i++){
        Node* currNext = curr->next;
        delete curr;
        curr = currNext;
    }*/

    return 0;
}
