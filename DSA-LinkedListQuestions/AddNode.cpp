#include "Node.cpp"
class AddNode{
public:
    //Function to insert a new node at given position in doubly linked list.
    void addNode(Node *head, int pos, int data){
       // Your code here
       Node* initialHead = head;
       Node* tail = head;

       Node* newNode = new Node(data);
       int length = 0;
       while(head != NULL) {
           length++;
           tail = head;
           head = head->next;
       }
       //cout << length << " is length" << endl;
       if(pos == 0 && head == NULL){
           head = newNode;
           return;
       }
       else if(pos == 0){ //&& head->next == NULL){
            head = newNode;
            newNode->next = initialHead;
            initialHead->prev = newNode;
            return;
       }
       else if(pos == length){
           //insert at the very end right after the tail
           //cout << "Tail data "<< tail->data << " tail index " << pos << endl;
           //tail = tail->next;
           tail->next = newNode;
           newNode->prev = tail;
           return;
       }
       Node* prevNode;
       head = initialHead;
       for(int i = 0; i <= pos && head->next != NULL; i++){
           prevNode = head;
           head = head->next;
       }
       //insert after prevNode, before head
       prevNode->next = newNode;
       head->prev = newNode;
       newNode->prev = prevNode;
       newNode->next = head;

       head = initialHead;
    }
    void addNode2(Node *head, int pos, int data){


        int cnt = -1;
        Node * temp = head;
        while(cnt < pos)
        {
            cnt++;
            if(cnt == pos)
            {
                Node * temp1 = new Node (data);
                temp1-> next = temp-> next;
                temp-> next = temp1;
                temp1-> prev = temp;

            }
            else temp = temp-> next;


        }
    }
};
