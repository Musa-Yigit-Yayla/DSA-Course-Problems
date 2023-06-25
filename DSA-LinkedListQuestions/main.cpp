//#include "LoopLength.cpp"
//#include "LinkedListInsert.cpp"
//#include "ReverseSll.cpp"
//#include "AddTwoLists.cpp"
//#include "CircularLinkedList.cpp"
//#include "SwapKthNodes.cpp"
//#include "MergeSortDll.cpp"
//#include "SegregateSll.cpp"
//#include "RemoveLoop.cpp"
#include "isPalindromeSll.cpp"
#include <iostream>

/*struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

void printList(Node* head);

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

    //SwapKthNodes skn;
    /*Node* head = new Node(1);
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
    head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = new Node(16);*/
    /*Node* head = new Node(2);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    //head->next->next->next->next->next = new Node(0);*/
    //head->next->next->next->next->next->next = new Node(2);
    //head->next->next->next->next->next->next->next = new Node(2);
    //head->next->next->next->next = new Node(806);
    //failed the following input sequence
    //16 8
    //90 78 66 68 47 33 37 48 85 73 13 24 10 7 53 59
    //head = skn.swapkthnode(head, 2, 2);
    //skn.printList(head, 4);

    //MergeSortDll msd;
    //head = msd.sortDoubly(head);
    //8
    //1 2 2 1 2 0 2 2
    //5
    //2 2 1 2 1
    /*SegregateSll ss;
    head = ss.segregate3(head);
    printList(head, 5);*/
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    isPalindromeSll ips;
    cout << ips.isPalindrome(head) << endl;
    return 0;
}
void printList(Node* head){
        Node* currNode = head;
        int counter = 0;
        while(currNode != NULL){
            cout << currNode->data << " ";
            currNode = currNode->next;
            counter++;
        }
        cout << endl;
}
