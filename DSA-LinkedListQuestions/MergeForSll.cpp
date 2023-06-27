#include "Node.cpp"
#include <cstddef>

class MergeForSll{
  private:
    int initialLength;
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        //retrieve the initial length
        Node* curr = head;
        int length = 0;
        while(curr != NULL){
            length++;
            curr = curr->next;
        }
        this->initialLength = length;
        if(length == 0 || length == 1){
            return head;
        }
        Node* h1 = head;
        Node* h2 = nullptr;
        int length1;
        if(length % 2 == 0){
            h2 = this->nodeAt(head, length / 2);
            length1 = length / 2;
        }
        else{
            h2 = this->nodeAt(head, (length / 2) + 1);
            length1 = length / 2 + 1;
        }
        return this->merge(h1 , h2, length1, length - length1);
    }
    //Merges two sorted sublists into one almost thoroughly inplace
    Node* merge(Node* h1, Node* h2, int l1 ,int l2){
        if(l2 == 0){
            return h1;
        }
        else if(l1 == 0){
            return h2;
        }
        else if(l1 == 1 && l2 == 1){
            //both h1 and h2 are guaranteed to be of length 1
            Node* newList = this->sortedMerge(h1, h2);
            return newList;
        }
        else if(l1 == 2 && l2 == 1){
            //sort the h1 first, then mergeSort both
            h1 = this->sortedMerge(h1, h1->next);
            Node* newList = this->sortedMerge(h1, h2);
            return newList;
        }
        else{
            Node* sortedH1 = nullptr;
            Node* sortedH2 = nullptr;

            int midL1;
            if(l1 % 2 == 0){
                //l1 is even
                midL1 = l1 / 2;
            }
            else{
                midL1 = l1 / 2 + 1;
            }

            int midL2;
            if(l2 % 2 == 0){
                //l1 is even
                midL2 = l2 / 2;
            }
            else{
                midL2 = l2 / 2 + 1;
            }
            //Cut the connecting pointers so as to avoid prospective errors
            Node* end1 = this->nodeAt(h1, midL1);
            Node* end2 = this->nodeAt(h2, midL2);
            if(end1 != NULL)
                end1->next = nullptr;
            if(end2 != NULL)
                end2->next = nullptr;
            //Make sure that the below indexes are correct
            sortedH1 = this->merge(h1, end1,  midL1, l1 - midL1);
            sortedH2 = this->merge(h2, end2, midL2, l2 - midL2);
            return this->sortedMerge(sortedH1, sortedH2);
        }
    }
    Node* sortedMerge(Node* head1, Node* head2)
    {
        // code here
        int l1 = 0;
        int l2 = 0;

        Node* h1 = head1;
        Node* h2 = head2;
        while(h1 != NULL){
            l1++;
            h1 = h1->next;
        }
        while(h2 != NULL){
            l2++;
            h2 = h2->next;
        }
        //l1 is bigger or equal to l2
        if(l1 < l2){
            Node* temp = head2;
            head2 = head1;
            head1 = temp;

            int templ = l2;
            l2 = l1;
            l1 = templ;
        }
        Node* prev1 = nullptr; // prev of curr1
        Node* curr1 = head1;
        Node* curr2 = head2;
        Node* curr2Next = nullptr;

        //for(int i = 0; i < l1 + l2; i++){
        while(curr1 != NULL && curr2 != NULL){
            if(curr1->data >= curr2->data){
                curr2Next = curr2->next;
                curr2->next = curr1;
                if(prev1 != NULL){
                    prev1->next = curr2;
                    prev1 = curr2;
                }
                else{
                    prev1 = curr2;
                    head1 = curr2;
                }

                curr2 = curr2Next;
                //prev1 = curr1;
            }
            else{
                prev1 = curr1;
                curr1 = curr1->next;
            }
        }
        if(prev1 != NULL && head2 != NULL && (prev1->data < head2->data)){
            prev1->next = head2;
        }
        else if((curr2Next != NULL && (prev1->data < curr2Next->data))){
            prev1->next = curr2Next;
        }
        /*while(curr2 != NULL){
            curr1->next = curr2;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }*/
        return head1;

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
