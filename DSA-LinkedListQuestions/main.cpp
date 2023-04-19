#include "LoopLength.cpp"
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
    next->next->next->next->next = next;

    LoopLength ll;
    cout << ll.countNodesinLoop(&head) << endl;

    return 0;
}
