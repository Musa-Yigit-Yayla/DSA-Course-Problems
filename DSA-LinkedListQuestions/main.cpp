//#include "LoopLength.cpp"
//#include "LinkedListInsert.cpp"
//#include "ReverseSll.cpp"
//#include "AddTwoLists.cpp"
//#include "CircularLinkedList.cpp"
#include "SwapKthNodes.cpp"
#include <iostream>


using namespace std;
int main(){
    /*Node head(4);
    Node* next = new Node(3);
    head.next = next;
    next->next = new Node(2);
    next->next->next = new Node(5);
    next->next->next->next = new Node(6);
    next->next->next->next->next = &head;

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
    head2->next->next->next->next->next->next->next->next->next->next->next->next->next->next = head2;
    int sllLength = 6;

    /*LoopLength ll;
    cout << ll.countNodesinLoop(&head) << endl;

    Node* n1 = new Node(13);
    Node* n2 = new Node(70);

    LinkedListInsert lli;
    lli.insertAtBegining(&n1);
    lli.insertAtEnd(&n2);*/


    //AddTwoLists atl;
    //Node* newList = atl.addTwoList(&head, head2);
    /*
    CircularLinkedList cll;
    cll.reverseCircularLinkedList(head2);
    cll.printList(&head);
    */
    /*cout << newList->data << endl;
    cout << atl.nodeAt(&head, 3)->data << endl;
    cout << atl.nodeAt(&head, 2)->data << endl;*/

    /*Node* curr = head.next;
    for(int i = 0; i < sllLength - 1; i++){
        Node* currNext = curr->next;
        delete curr;
        curr = currNext;
    }*/

    SwapKthNodes skn;
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->next->next = new Node(9);
    head->next->next->next->next->next->next->next->next->next = new Node(10);
    head->next->next->next->next->next->next->next->next->next->next = new Node(11);
    head->next->next->next->next->next->next->next->next->next->next->next = new Node(12);
    head->next->next->next->next->next->next->next->next->next->next->next->next = new Node(12);
    head->next->next->next->next->next->next->next->next->next->next->next->next->next = new Node(12);
    head->next->next->next->next->next->next->next->next->next->next->next->next->next->next = new Node(12);
    head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = new Node(16);
    //head->next->next->next->next = new Node(806);
    //failed the following input sequence
    //16 8
    //90 78 66 68 47 33 37 48 85 73 13 24 10 7 53 59
    head = skn.swapkthnode(head, 16, 8);
    skn.printList(head, 4);
    return 0;
}
