#include "Node.cpp"
#include <cstddef>

//Function to merge two sorted linked list.
class MergeSortSll{
public:
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
        if(prev1->data < head2->data){
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
};
