#include <cstddef>
//#include "Node.cpp"
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

using namespace std;
class isPalindromeSll{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        //initially retrieve the length of given sll
        int length = 0;
        Node* curr = head;
        while(curr != NULL){
            length++;
            curr = curr->next;
        }
        if(length == 0 || length == 1){
            return true;
        }
        int i = 0;
        while(i < length / 2){
            Node* left = this->nodeAt(head, i);
            Node* right = this->nodeAt(head, length - i);
            if(left->data != right->data){
                return false;
            }
            i++;
        }
        return true;
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
