#include <cmath>
#include <string>
#include "Node.cpp"
/*struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
using namespace std;
class AddTwoLists{
public:
    //Function to add two numbers represented by linked list.
    Node* addTwoList(Node* first, Node* second){
        // code here
        int l1 = 0;
        int l2 = 0;
        Node* firstHead = first;
        Node* secondHead = second;

        while(first != NULL){
            l1++;
            first = first->next;
        }
        while(second != NULL){
            l2++;
            second = second->next;
        }
        first = firstHead;
        second = secondHead;

        int n1 = 0, n2 = 0;
        for(int i = l1; i >= 1; i--){
            int nodeIndex = l1 - i;
            Node* currNode = this->nodeAt(first, nodeIndex);
            n1 += pow(10, l1 - i) * currNode->data;
        }
        for(int i = l2; i >= 1; i--){
            int nodeIndex = l2 - i;
            Node* currNode = this->nodeAt(second, nodeIndex);
            double x =  pow(10, l2 - i) * currNode->data;
            n2 += pow(10, l2 - i) * currNode->data;
        }
        string s1 = this->reverseNum(n1);
        string s2 = this->reverseNum(n2);
        n1 = stoi(s1);
        n2 = stoi(s2);
        int sum = n1 + n2;
        string sumString = to_string(sum);
        int size = sumString.size();

        Node* newHead = nullptr;
        Node* prev = nullptr;
        for(int i = size; i >= 1; i--){
            int currDigit = sum / pow(10, i - 1);
            Node* currNode = new Node(currDigit);
            if(i == size){
                newHead = currNode;
                prev = currNode;
            }
            else{
                prev->next = currNode;
                prev = prev->next;
            }
            double x = pow(10, i - 1);
            sum %= (int)(pow(10, i - 1));
        }
        return newHead;
    }
    //Does no bounds checking
    //User is responsible of ensuring that the position is valid
    //0 based indexing
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
    string reverseNum(int n1){
        string s1 = to_string(n1);
        string result = "";
        for(int i = 0; i < s1.size(); i++){
            char ch = s1.at(s1.size() - 1 - i);
            result += ch;
        }
        return result;
    }
    //Function to swap Kth node from beginning and end in a linked list.
    Node* swapkthnode(Node* head, int n, int k)
    {
        // Your Code here
        if(n <= 1){
            return head;
        }
        Node* initialHead = head;

        int length = 0;
        while(initialHead != NULL){
            length++;
            initialHead = initialHead->next;
        }
        if(k == 1){
            //swap the head with end
            Node* headNext = head->next;
            Node* last = nodeAt(head, length);
            Node* lastPrev = nodeAt(head, length - 1);
            lastPrev->next = head;
            head->next = nullptr;
            last->next =headNext;
            head = last;

        }
        else if(length - k != k){
            Node* low = nodeAt(head, k - 1);
            Node* lowPrev = nodeAt(head, k - 2);
            Node* lowNext = nodeAt(head, k);

            Node* high = nodeAt(head, length - (k - 1));
            Node* highNext = nodeAt(head, length - (k - 2));
            Node* highPrev = nodeAt(head, length - k);

            lowPrev->next = high;
            high->next = lowNext;

            highPrev->next = low;
            low->next = highNext;
        }
        return head;
    }
    //delete the given node without the head pointer
    //It is assumed that the given node is not the tail
    void deleteNode(Node* del)
    {
       // Your code here
       //Node* initialDel = del;
       //delete initialDel;
       Node* temp = del->next;
       del->data = temp->data;
       del->next = temp->next;
       delete temp;
    }
};

