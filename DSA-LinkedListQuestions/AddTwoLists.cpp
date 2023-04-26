#include <cmath>
#include <string>

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
class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
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
            n2 += pow(10, l2 - i) * currNode->data;
        }
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
            }
            else{
                prev->next = currNode;
            }
            sum /= pow(10, i - 1);
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
};

