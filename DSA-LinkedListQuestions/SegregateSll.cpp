#include <unordered_map>
#include "Node.cpp"
#include <iostream>

using namespace std;
class SegregateSll{
public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {

        // Add code here
        unordered_map<int, int> map;

        Node* currNode = head;
        while(currNode != NULL){
            int value = currNode->data;

            switch(value){
                case 0:
                    if(map.count(0) == 0){
                        map.insert({0, 1});

                    }
                    else
                        map.at(0)++;
                    break;
                case 1:
                    if(map.count(1) == 0){
                        map.insert({1, 1});
                    }
                    else
                        map.at(1)++;
                    break;

                case 2:
                    if(map.count(2) == 0){
                        map.insert({2, 1});
                    }
                    else
                        map.at(2)++;
                    break;
            }
            currNode = currNode->next;
        }
        int zeroLength = map.at(0);
        int oneLength = map.at(1);
        int twoLength = map.at(2);

        Node* newList = nullptr;
        Node* initialNewList = nullptr;

        int currLength = 0;
        bool isAdded = false;
        for(int i = 0; i < zeroLength; i++){
            //if(newList == nullptr){
                if(!isAdded){
                    newList = new Node(0);
                    initialNewList = newList;
                }
                else{
                    newList = newList->next;
                    newList = new Node(0);
                    (initialNewList + currLength - 1)->next = newList;
                    //newList = newList->next;
                    //newList = newList->next;
                }
                isAdded = true;
            //}
            //newList = newList->next;
            currLength++;
        }
        for(int i = 0; i < oneLength; i++){
            //if(newList == nullptr){
                if(!isAdded){
                    newList = new Node(1);
                    initialNewList = newList;
                }
                else{
                    if(i != 0)
                        newList = newList->next;
                    newList = new Node(1);
                    Node* currNl = (initialNewList + currLength - 1);
                    currNl->next = newList;
                    //newList = newList->next;
                    //newList = newList->next;
                }
                isAdded = true;
            //}
            //newList = newList->next;
            currLength++;
        }
        for(int i = 0; i < twoLength; i++){
            //if(newList == nullptr){
                if(!isAdded){
                    newList = new Node(2);
                    initialNewList = newList;
                }
                else{
                    if(i != 0)
                        newList = newList->next;
                    newList = new Node(2);
                    (initialNewList + currLength - 1)->next = newList;
                    //newList = newList->next;
                    //newList = newList->next;
                }
                isAdded = true;
            currLength++;
        }

        //}
        return initialNewList;
    }
    //Segregates any linked list with any int value in place
    //Uses bubble sort
    Node* segregate2(Node* head){
        //calculate the length initially
        int length = 0;
        Node* currNode = head;
        while(currNode != NULL){
            length++;
            currNode = currNode->next;
        }
        for(int i = 0; i < length - 1; i++){
            for(int j = 0; j < length - 1 - i; j++){
                //compare jth and its next element and perform swap operation if necessary
                Node* n1 = this->nodeAt(head, j);
                Node* n2 = this->nodeAt(head, j + 1);
                if(n1->data > n2->data){
                    this->swap(n1, n2);
                }
            }
        }
        return head;
    }
    Node* segregate3(Node* head){
        unordered_map<int, int> map;

        int zeroLength = 0;
        int oneLength = 0;
        int twoLength = 0;

        Node* currNode = head;
        while(currNode != NULL){
            int value = currNode->data;

            switch(value){
                case 0:
                    if(map.count(0) == 0){
                        map.insert({0, 1});
                    }
                    else
                        map.at(0)++;
                    break;
                case 1:
                    if(map.count(1) == 0){
                        map.insert({1, 1});
                    }
                    else
                        map.at(1)++;
                    break;

                case 2:
                    if(map.count(2) == 0){
                        map.insert({2, 1});
                    }
                    else
                        map.at(2)++;
                    break;
            }
            currNode = currNode->next;
        }
        if(map.count(0) != 0)
            zeroLength = map.at(0);
        if(map.count(1) != 0)
            oneLength = map.at(1);
        if(map.count(2) != 0)
            twoLength = map.at(2);

        bool is0Exhausted = (zeroLength == 0);
        bool is1Exhausted = (oneLength == 0);
        bool is2Exhausted = (twoLength == 0);

        int totalLength = zeroLength + oneLength + twoLength;

        Node* newList = this->createList(totalLength);
        currNode = newList;
        for(int i = 0; i < totalLength; i++){
            if(zeroLength != 0){
                currNode->data = 0;
                zeroLength--;
            }
            else if(oneLength != 0){
                currNode->data = 1;
                oneLength--;
            }
            else if(twoLength != 0){
                currNode->data = 2;
                twoLength--;
            }
            currNode = currNode->next;
        }
        return newList;

    }
    //Creates a singly linked list of given length
    Node* createList(int length){
        int initialLength = length;
        Node* head = new Node(INT_MIN);
        Node* headNext = nullptr;
        Node* currNode = nullptr;
        do{
            Node* newNode = new Node(INT_MIN);
            if(length == initialLength){
                head->next = newNode;
                currNode = newNode;
            }
            else{
                currNode->next = newNode;
                currNode = currNode->next;
            }
            length--;
        }while(length > 0);
        return head->next;
    }
    void swap(Node* n1, Node* n2){
        int temp = n1->data;
        n1->data = n2->data;
        n2->data = temp;
    }
    //Checks whether the given linked list is sorted in ascending order
    bool isSorted(Node* head){
        Node* currNode = head->next;
        Node* prevNode = head;
        while(currNode != NULL){
            if(prevNode->data > currNode->data){
                return false;
            }
            prevNode = currNode;
            currNode = currNode->next;
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
    //Assumes that the given lists length is non-zero
    Node* getTailNode(Node* head){
        Node* currNode = head;
        Node* prevNode = nullptr;
        while(currNode != NULL){
            prevNode = currNode;
            currNode = currNode->next;
        }
        return prevNode;
    }
};
