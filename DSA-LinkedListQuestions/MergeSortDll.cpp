/*    Structure of the node of the list is as
struct Node
{
	int data;
	struct Node *next, *prev;
	Node (int x){
	    data = x;
	    next = prev = NULL;
	}
}; */
#include <cmath>
#include "Node.cpp"

using namespace std;
class MergeSortDll{
private:
Node* head = nullptr;
int initialLength;

public:
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
inline int getSllLength(struct Node* head){
    int length = 0;
    struct Node* currNode = head;
    while(currNode != NULL){
        length++;
        currNode = currNode->next;
    }
    return length;
}
Node* merge(Node* firstHalf, Node* secondHalf){
    int length1 = getSllLength(firstHalf);
    int length2 = getSllLength(secondHalf);

    int i = 0; //index for newList
    int i1 = 0;
    int i2 = 0;
    bool isI1Exhausted = false, isI2Exhausted = true;

    Node* newList = nullptr;

    while(!(isI1Exhausted || isI2Exhausted)){ //and gate with an inverter at the inputs
        if(i1 >= length1){
            isI1Exhausted = true;
        }
        else if(i2 >= length2){
            isI2Exhausted = true;
        }
        Node* n1 = nodeAt(firstHalf, i1);
        Node* n2 = nodeAt(secondHalf, i2);

        //Might be problematic here
        bool isIProcessed = false;
        int processedI = i;
        if(i != 0){
            processedI -= 1;
            isIProcessed = true;
        }
        if(n1->data < n2->data){
            Node* listNode = nodeAt(newList, processedI);
            listNode->next = n1;
            n1->prev = listNode;
            i1++;
        }
        else{
            Node* listNode = nodeAt(newList, processedI);
            listNode->next = n2;
            n2->prev = listNode;
            i2++;
        }
        i++;
        if(isIProcessed){
            i++;
        }
    }
    if(isI1Exhausted){
        while(!isI2Exhausted){
            Node* n2 = nodeAt(secondHalf, i2);
            Node* listNode = nodeAt(newList, i);
            listNode->next = n2;
            n2->prev = listNode;

            i++;
            if(i2 >= length2){
                isI2Exhausted = true;
            }
        }
    }
    else{// secondHalf is exhausted
        while(!isI1Exhausted){
            Node* n1 = nodeAt(firstHalf, i1);
            Node* listNode = nodeAt(newList, i);
            listNode->next = n1;
            n1->prev = listNode;

            i++;
            if(i1 >= length1){
                isI1Exhausted = true;
            }
        }
    }
    return newList;
}
//l stands for length
//i1 represents starting index
Node* sortAscendingHelper(Node* head, const int i1, int l){
    if(l == 1){
        Node* minNode = nodeAt(head, i1);
        /*Node* otherNode = nodeAt(i2);
        if(otherNode->data < minNode->data){
            Node* tempNode = minNode;
            minNode = otherNode;
            otherNode = temp;
        }
        Node* mergedList = minNode;
        minNode->next = otherNode;
        otherNode->next = nullptr;*/
        //Might be problematic here !!!!!
        return minNode;
    }
    else{
        int i2 = i1 + (l / 2);
        Node* firstHalf = sortAscendingHelper(head + i1, i1, l / 2); //these two lines might be problematic (including the below line)
        Node* secondHalf = sortAscendingHelper(head + i2 + 1, i2 + 1, i2 + l / 2);

        Node* firstHalfTail = nodeAt(firstHalf, i2);

        //firstHalfTail->next = secondHalf;
        Node* mergedList = merge(firstHalf, secondHalf);
        //int length2 = getSllLength(secondHalf);
        //Node* secondHalfTail = nodeAt(secondHalf, length2 - 1);

        //secondHalfTail->next = nullptr;

        return mergedList;
    }
}
Node* sortAscending(Node* head){
    int length = getSllLength(head);
    return sortAscendingHelper(head, 0, length - 1);
}
//Function to sort the given doubly linked list using Merge Sort.
struct Node *sortDoubly(struct Node *head)
{
	// Your code here
	this->head = head;
	int length = getSllLength(head);
	this->initialLength = length;

	Node* ascendingList = sortAscending(head);
	return ascendingList;
}

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
       // Your code here
    //initially we must find the length of our linked list
    int length = 0;
    Node* currNode = head;
    while(currNode != NULL){
        length++;
        currNode = currNode->next;
    }

    if(length - n < 0){
        return -1;;
    }
    Node* givenNode = nodeAt(head, length - n);
    return givenNode->data;
}

};
