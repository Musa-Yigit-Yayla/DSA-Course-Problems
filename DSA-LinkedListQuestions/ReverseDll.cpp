
class ReverseDll{
public:
    Node* reverseDoublyLinkedList(Node* head){
        //First traverse the dll compeletely to retrieve the tail
        Node* initialHead = head;
        Node* tail;
        Node* initialTail;
        Node* resultHead;
        int length = 0;
        while(head != NULL){
            tail = head;
            head = head->next;
            length++;
        }
        initialTail = tail;
        if(length == 0 || length == 1){
            return;
        }
        for(int i = 0; i < length / 2; i++){
            int low = i;
            int high = length - i - 1;



            if(i == 0){
                Node* headNext = head->next;
                Node* tailPrev = tail->prev;

                head = tail;
                head->next = headNext;
                headNext->prev = head;
                tail = initialHead;
                tail->prev = tailPrev;
                tailPrev->next = tail;

                resultHead = tail;
            }
            else{
                Node* n1 = this->nodeAt(low);
                Node* n2 = this->nodeAt(high);

                Node* n1Prev = n1->prev;
                Node* n1Next = n1->next;

                Node* n2Prev = n2->prev;
                Node* n2Next = n2->next;

                //swap n1 and n2

                Node* initialN1 = n1;

                n2->prev = n1Prev;
                n1Prev->next = n2;
                n2->next = n1Next;
                n1Next->prev = n2;

                n1->prev = n2Prev;
                n2Prev->next = n1;
                n1->next = n2Next;
                n2Next->prev = n1;

            }
        }
        return resultHead
    }
    //Does no bounds checking
    //User is responsible of ensuring that the position is valid
    //0 based indexing
    Node* nodeAt(Node* head, int pos){
        Node* initialHead = head;
        for(int i = 0; i < pos; i++){
            head = head->next;
        }
        Node* result = head;
        head = initialHead;
        return result;
    }

};
