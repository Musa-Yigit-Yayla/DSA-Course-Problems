//#include "LoopLength.cpp"
//#include "LinkedListInsert.cpp"
#include "ReverseSll.cpp"
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
    Node head(1);
    Node* next = new Node(2);
    head.next = next;
    next->next = new Node(3);
    next->next->next = new Node(4);
    next->next->next->next = new Node(5);
    next->next->next->next->next = new Node(6);
    int sllLength = 6;

    /*LoopLength ll;
    cout << ll.countNodesinLoop(&head) << endl;

    Node* n1 = new Node(13);
    Node* n2 = new Node(70);

    LinkedListInsert lli;
    lli.insertAtBegining(&n1);
    lli.insertAtEnd(&n2);*/


    ReverseSll rs;
    rs.reverseList(&head);

    cout << head.data << endl;
    cout << rs.nodeAt(&head, 5)->data << endl;
    cout << rs.nodeAt(&head, 2)->data << endl;

    Node* curr = head.next;
    for(int i = 0; i < sllLength - 1; i++){
        Node* currNext = curr->next;
        delete curr;
        curr = currNext;
    }

    return 0;
}
